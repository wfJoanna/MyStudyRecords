from pyspark import Row
from pyspark.sql import SparkSession

spark = SparkSession \
    .builder \
    .appName("lex-spark") \
    .master("local[*]") \
    .getOrCreate()

sc = spark.sparkContext
file = r".\lex.txt"  # 修改1
rdd = sc.textFile(file)

info = rdd.map(lambda x: x.split("\t"))  # lex.txt的分割方式是/t
info_array = info.collect()  # info_array就是有270个元素的数组，而每个元素又是一个数组，比如info_array[0][1]就是"858551"
cal_result = ['动画区', 'LexBurner']  # 修改2


def calculator(item, cal_result):
    view_time_sum = 0  # 播放量总和
    viewer_involve_sum = 0  # 观众参与度总和
    viewer_support_sum = 0  # 观众支持度总和
    view_time_count = 0  # 在选取的时间段内的视频个数
    for i in range(0, 270):  # 因为lex.txt一共270行 #修改3
        year = int(item[i][0][0:4])  # 得到该视频的发布年
        month = int(item[i][0][5:7])  # 得到该视频的发布月
        if (year == 2018 and month >= 7) or (year >= 2019):  # 筛选出我们要的时间段内的视频
            view_time = int(item[i][1])  # 取得该视频的播放量
            view_time_sum += view_time
            viewer_involve = (int(item[i][2]) + int(item[i][3])) * 10000 // view_time  # 取得该视频的参与度/0.0001
            viewer_involve_sum += viewer_involve
            viewer_support = (int(item[i][4]) + int(item[i][5]) + int(
                item[i][6])) * 1000 // view_time  # 取得该视频的支持度/0.001
            viewer_support_sum += viewer_support
            view_time_count += 1
    cal_result.append(view_time_sum // view_time_count // 10000)
    cal_result.append(viewer_involve_sum // view_time_count)
    cal_result.append(viewer_support_sum // view_time_count)


calculator(info_array, cal_result)
print(cal_result)
real_result = [cal_result]


def f(item):
    data = {}
    data["area_name"] = item[0]
    data["up_name"] = item[1]
    data["traffic"] = item[2]
    data["viewer_involve"] = item[3]
    data["viewer_support"] = item[4]
    return data


result_rdd = sc.parallelize(real_result)

result_df = result_rdd.map(lambda x: Row(**f(x))).toDF()
result_df.show()

conn_param = {}
conn_param['user'] = "root"
conn_param['password'] = "root"
conn_param['driver'] = "com.mysql.jdbc.Driver"
result_df.write.jdbc("jdbc:mysql://localhost:3306/bilibili?serverTimezone=UTC", 'represent_up_situ', 'append',
                     conn_param)
print("执行完毕")

# 备注
# traffic 是近两年 视频平均播放量除以10000
# viewer_involve 是近两年 （弹幕+评论）/播放量 然后除以0.0001
# viewer_support 是近两年 （点赞+投币+收藏）/播放量 然后除以0.001
