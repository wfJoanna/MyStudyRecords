from pyspark import Row
from pyspark.sql import SparkSession

spark = SparkSession \
    .builder \
    .appName("spark1") \
    .master("local[*]") \
    .getOrCreate()

sc = spark.sparkContext
file = r".\area_heat_info.txt"
rdd = sc.textFile(file)

lines = rdd.map(lambda x: x.split("\t"))


def group(line):
    name = line[0]
    view = float(line[1])
    return name, view


def arealist(lines):
    area_view_rdd = lines.map(lambda x: group(x)).reduceByKey(lambda x, y: round((x + y), 2))  # 以区为基本单元相加播放量

    view_all = 0
    area_view_list = area_view_rdd.collect()
    for x in area_view_list:
        view_all += x[1]  # 得到播放量总和

    area_rdd = area_view_rdd.map(lambda x: Row(area_name=x[0], area_rate=round((x[1] * 100 / view_all), 2)))
    area_df = spark.createDataFrame(area_rdd)
    return area_df


area_df = arealist(lines)
area_df.show()

conn_param = {}
conn_param['user'] = "root"
conn_param['password'] = "root"
conn_param['driver'] = "com.mysql.jdbc.Driver"
area_df.write.jdbc("jdbc:mysql://localhost:3306/bilibili?serverTimezone=UTC&useSSL=false", 'area_click', 'overwrite', conn_param)

print("执行完毕")
