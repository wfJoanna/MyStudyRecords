import operator

import numpy as np

"""
k-近邻算法的一般流程：
1.收集数据：datingTestSet.txt
2.准备数据：file2matrix()、autoNorm()
3.分析数据：数据可视化之类的
4.测试算法：classify0()、datingClassTest()，计算错误率，可调整k值和hoRatio
5.使用算法：classifyPerson()
"""


def file2matrix(filename):  # 读取文件中的数据成规范格式
    fr = open(filename)
    arrayOfLines = fr.readlines()  # 返回的是一个列表，元素是文件的每一行内容
    numberOfLines = len(arrayOfLines)
    returnMat = np.zeros((numberOfLines, 3))  # 生成一个全为0的矩阵。要想全为1的话同理可使用np.ones()
    classLabelVector = []
    index = 0  # 等会儿要用到的arrayOfLines的索引值

    for line in arrayOfLines:
        line = line.strip()  # strip()删除字符串开头和结尾的空白符'\n','\t',' ','\r'
        listFromLine = line.split('\t')  # split()对字符串进行分割，返回列表
        returnMat[index, :] = listFromLine[0:3]  # 文件内容的非标签部分均存入了zeroMat
        if listFromLine[-1] == 'didntLike':
            classLabelVector.append(1)
        elif listFromLine[-1] == 'smallDoses':
            classLabelVector.append(2)
        elif listFromLine[-1] == 'largeDoses':
            classLabelVector.append(3)  # 根据文件内容里的标签进行分类
        index += 1

    return returnMat, classLabelVector


def autoNorm(dataSet):  # 数据归一化。因为要进行kNN的话，有一列数据差值太大了，对计算结果的影响远超其他两个特征，所以我们要数据归一化
    # 归一化的公式为 newValue = (oldValue - min) / (max - min) ，使得每个值都在0~1
    minVals = dataSet.min(0)  # list.min(0)返回每一列最小值组成的一维数组，list.min(1)返回每一行最小值组成的一维数组
    maxVals = dataSet.max(0)  # max同上
    ranges = maxVals - minVals  # 获得每一列的数据范围
    normDataSet = np.zeros(np.shape(dataSet))  # shape()返回数组的行数和列数组成的一个元组
    m = dataSet.shape[0]  # 得到dataSet的行数
    normDataSet = dataSet - np.tile(minVals, (m, 1))
    normDataSet = normDataSet / np.tile(ranges, (m, 1))
    return normDataSet, ranges, minVals


def classify0(inTest, dataSet, classes, k):
    dataSetSize = dataSet.shape[0]
    inMat = np.tile(inTest, (dataSetSize, 1))
    middle1 = (dataSet - inMat) ** 2
    middle2 = middle1.sum(axis=1)
    distances = middle2 ** 0.5
    sortedIndices = distances.argsort()
    classCount = {}
    for i in range(k):
        getClass = classes[sortedIndices[i]]
        classCount[getClass] = classCount.get(getClass, 0) + 1
    sortedClassCount = sorted(classCount.items(), key=operator.itemgetter(1), reverse=True)
    return sortedClassCount[0][0]


def datingClassTest():
    filename = 'datingTestSet.txt'
    datingDataMat, datingLabels = file2matrix(filename)
    hoRatio = 0.10  # 取所有数据的10%为测试数据
    normDataSet, ranges, minVals = autoNorm(datingDataMat)
    m = normDataSet.shape[0]
    numOfTest = int(m * hoRatio)
    errorCount = 0.0

    for i in range(numOfTest):
        classifyResult = classify0(normDataSet[i, :], normDataSet[numOfTest:m, :], datingLabels[numOfTest:m], 4)
        print("分类结果：%d\t真是类别：%d" % (classifyResult, datingLabels[i]))
        if classifyResult != datingLabels[i]:
            errorCount += 1.0

    print("错误率：%f%%" % (errorCount / float(numOfTest) * 100))


def classifyPerson():
    resultList = ['讨厌', '有些喜欢', '非常喜欢']
    A = float(input("每年获得的飞行常客里程数:"))
    B = float(input("玩视频游戏所耗时间百分比:"))
    C = float(input("每周消费的冰激淋公升数:"))
    filename = "datingTestSet.txt"
    datingDataMat, datingLabels = file2matrix(filename)
    normDataSet, ranges, minVals = autoNorm(datingDataMat)
    inArr = np.array([A, B, C])
    norminArr = (inArr - minVals) / ranges
    classifyResult = classify0(norminArr, normDataSet, datingLabels, 3)
    print("你可能%s这个人" % (resultList[classifyResult - 1]))


if __name__ == '__main__':
    datingClassTest()
    classifyPerson()
