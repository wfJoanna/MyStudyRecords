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
file = "hdfs://master:9000/input/时长.txt"
rdd = sc.textFile(file)

lines = rdd.map(lambda x: x.split("\t"))


def group(line):
    minute = int(line[0].split(":")[0])
    view = int(line[1])
    if (minute >= 0 and minute <= 5):
        minutes = "0~5"
    elif (minute >= 6 and minute <= 10):
        minutes = "6~10"
    elif (minute >= 11 and minute <= 20):
        minutes = "11~20"
    elif (minute >= 21 and minute <= 40):
        minutes = "21~40"
    else:
        minutes = "41~∞"
    return minutes, (view, 1)


def timedivide(lines):
    time_rdd = lines.map(lambda x: group(x)).reduceByKey(lambda x, y: (x[0] + y[0], x[1] + y[1]))
    time_real_rdd = time_rdd.map(lambda x: Row(duration=x[0], heat=int(x[1][0] / x[1][1])))
    time_df = spark.createDataFrame(time_real_rdd)
    return time_df


time_df = timedivide(lines)
time_df.show()

conn_param = {}
conn_param['user'] = "root"
conn_param['password'] = "root"
conn_param['driver'] = "com.mysql.cj.jdbc.Driver"
time_df.write.jdbc("jdbc:mysql://192.168.2.101:3306/test?serverTimezone=UTC&useSSL=false", 'video_time_click',
                   'overwrite', conn_param)

print("执行完毕")
