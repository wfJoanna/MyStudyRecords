import operator

import numpy as np


def createDataSet():  # 创建数据集
    createGroup = np.array([[1, 101], [5, 89], [108, 5], [115, 8]])
    createLabels = ['爱情片', '爱情片', '动作片', '动作片']
    return createGroup, createLabels


def classify0(inTest, dataSet, classes, k):
    dataSetSize = dataSet.shape[0]  # 求得样本数据个数
    inMat = np.tile(inTest, (dataSetSize, 1))  # 把测试数据拉成和样本一样规格的矩阵
    middle1 = (dataSet - inMat) ** 2
    middle2 = middle1.sum(axis=1)
    distances = middle2 ** 0.5  # 算出了测试数据与各个样本点的距离
    sortedIndices = distances.argsort()  # 距离从小到大排序后的索引值，注意是索引值

    classCount = {}
    for i in range(k):  # 0,1,...,k-1
        getClass = classes[sortedIndices[i]]  # 对应的种类
        classCount[getClass] = classCount.get(getClass, 0) + 1
        # 字典的get()方法：dict.get(key,default=None)，返回指定key的值，如果没有就返回第二个参数
        # 我们就得到了种类对应的次数

    sortedClassCount = sorted(classCount.items(), key=operator.itemgetter(1), reverse=True)
    # sort()和sorted()的区别：sort()改变了原对象，sorted()没有改变原对象而是返回了一个新的对象
    # sorted()：第一个参数是对象，第二个参数是用来进行比较的元素，第三个参数是排序规则
    # 这里第一个参数解释：items()函数以列表返回可遍历的(键, 值)元组数组，就是变换了一个形式
    # 这里第二个参数解释：key=operator.itemgetter(1)根据字典的值进行排序，key=operator.itemgetter(0)根据字典的键进行排序
    # 这里第三个参数解释：reverse=True降序，reverse=False升序（默认）
    return sortedClassCount[0][0]


if __name__ == '__main__':
    group, labels = createDataSet()
    test = [101, 20]
    test_class = classify0(test, group, labels, 3)
    print(test_class)
