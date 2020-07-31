# !/usr/bin/python
from pyspark import Row
from pyspark.sql import SparkSession

spark = SparkSession \
    .builder \
    .appName("spark1") \
    .master("local[*]") \
    .config("spark.some.config.option","some-value") \
    .getOrCreate()

sc = spark.sparkContext
file = "hdfs://master:9000/input/fans_hundred_info.txt"
rdd = sc.textFile(file)

def group(item):
    return item[0],1

lines = rdd.map(lambda x: x.split("\t"))
up_rdd=lines.map(lambda x: group(x)).reduceByKey(lambda x,y:x+y)

amount_all = 0
up_list = up_rdd.collect()
for x in up_list:
    amount_all += x[1]

up_real_rdd=up_rdd.map(lambda x:Row(area_name=x[0], up_rate=round(x[1]*100/amount_all,2)))
up_df = spark.createDataFrame(up_real_rdd)
up_df.show()

conn_param = {}
conn_param['user'] = "root"
conn_param['password'] = "root"
conn_param['driver'] = "com.mysql.cj.jdbc.Driver"
up_df.write.jdbc("jdbc:mysql://192.168.2.101:3306/test?serverTimezone=UTC&useSSL=false", 'top_up_subarea', 'overwrite', conn_param)

print("执行完毕")
