import operator
import pickle
from math import log

"""
生成决策树，并保存至文本文件，之后就不用重复构建决策树了
"""


def createDataSet():
    dataSet = [[0, 0, 0, 0, 'no'],
               [0, 0, 0, 1, 'no'],
               [0, 1, 0, 1, 'yes'],
               [0, 1, 1, 0, 'yes'],
               [0, 0, 0, 0, 'no'],
               [1, 0, 0, 0, 'no'],
               [1, 0, 0, 1, 'no'],
               [1, 1, 1, 1, 'yes'],
               [1, 0, 1, 2, 'yes'],
               [1, 0, 1, 2, 'yes'],
               [2, 0, 1, 2, 'yes'],
               [2, 0, 1, 1, 'yes'],
               [2, 1, 0, 1, 'yes'],
               [2, 1, 0, 2, 'yes'],
               [2, 0, 0, 0, 'no']]
    features = ['年龄', '有工作', '有自己的房子', '信贷情况']
    return dataSet, features


def calcShannonEnt(dataSet):  # 计算经验熵（香农熵）
    numEntires = len(dataSet)  # 当len()里的参数是个二维数组时，返回数据集的行数
    labelCounts = {}
    for featVec in dataSet:
        currentLabel = featVec[-1]
        if currentLabel not in labelCounts.keys():  # 如果标签没有放入统计次数的字典,添加进去
            labelCounts[currentLabel] = 0
        labelCounts[currentLabel] += 1
    shannonEnt = 0.0
    for key in labelCounts:
        prob = float(labelCounts[key]) / numEntires
        shannonEnt -= prob * log(prob, 2)  # 经验熵计算公式我这儿懒得写了
    return shannonEnt


def splitDataSet(dataSet, axis, value):  # 按照给定特征划分数据集
    # dataSet:待划分的数据集，axis:划分数据集的特征，value:需要返回的特征的值
    returnDataSet = []
    for featVec in dataSet:
        if featVec[axis] == value:
            reducedFeatVec = featVec[:axis]
            reducedFeatVec.extend(featVec[axis + 1:])  # 这一行数据去掉了axis特征，同时注意最后一位是标签哦
            returnDataSet.append(reducedFeatVec)
    return returnDataSet


def chooseBestFeatureToSplit(dataSet):  # 选择信息增益最大的最优特征
    numFeatures = len(dataSet[0]) - 1  # 得到特征数量
    baseEntropy = calcShannonEnt(dataSet)  # 计算数据集的香农熵
    bestInfoGain = 0.0  # 信息增益的初始值
    bestFeature = -1  # 最优特征的索引值的初始值
    for i in range(numFeatures):
        featList = [example[i] for example in dataSet]  # 获取第i个特征的所有数据
        uniqueVals = set(featList)  # 创建集合，这样就删掉了featList里的重复数据
        newEntropy = 0.0  # 经验条件熵的初始值
        for value in uniqueVals:
            subDataSet = splitDataSet(dataSet, i, value)  # 返回splitDataSet划分后的子集
            prob = len(subDataSet) / float(len(dataSet))  # 计算子集的概率
            newEntropy += prob * calcShannonEnt(subDataSet)  # 经验条件熵的计算公式我就懒得写了
        infoGain = baseEntropy - newEntropy  # 信息增益公式
        if (infoGain > bestInfoGain):  # 其实就是看哪个特征的经验条件熵最小
            bestInfoGain = infoGain
            bestFeature = i
    return bestFeature


def majorityCnt(classList):  # 统计classList中出现次数最多的标签
    classCount = {}
    for vote in classList:
        if vote not in classCount.keys(): classCount[vote] = 0
        classCount[vote] += 1
    sortedClassCount = sorted(classCount.items(), key=operator.itemgetter(1), reverse=True)
    return sortedClassCount[0][0]


def createTree(dataSet, features, featLabels):  # 这里构建决策树采用的是ID3算法
    classList = [example[-1] for example in dataSet]  # 取所有标签，注意是包含重复的
    if classList.count(classList[0]) == len(classList):
        # 第一个停止条件是所有的类标签完全相同，则直接返回该类标签
        # 正常情况下，递归的最里头就是从这里返回的
        return classList[0]
    if len(dataSet[0]) == 1 or len(features) == 0:
        # 第二个停止条件是使用完了所有特征，仍然不能将数据划分仅包含唯一类别的分组，即决策树构建失败，特征不够用
        # 此时说明数据纬度不够，由于第二个停止条件无法简单地返回唯一的类标签，这里挑选出现数量最多的类别作为返回值
        return majorityCnt(classList)
    bestFeat = chooseBestFeatureToSplit(dataSet)
    bestFeatLabel = features[bestFeat]
    featLabels.append(bestFeatLabel)
    myTree = {bestFeatLabel: {}}
    del (features[bestFeat])  # 删除已经使用特征
    featValues = [example[bestFeat] for example in dataSet]  # 得到训练集中所有最优特征的属性值
    uniqueVals = set(featValues)  # 去掉重复的属性值
    for value in uniqueVals:
        subFeatures = features[:]  # 这和 subFeatures=features 没有区别。不直接用features而使用subFeatures的原因应该是方便阅读
        myTree[bestFeatLabel][value] = createTree(splitDataSet(dataSet, bestFeat, value), subFeatures, featLabels)  # 递归
    return myTree


def storeTree(inputTree, filename):  # 存储决策树
    with open(filename, 'wb') as fw:  # 以二进制格式打开一个文件只用于写入。如果该文件已存在则打开文件，并从开头开始编辑，即原有内容会被删除
        pickle.dump(inputTree, fw)


if __name__ == '__main__':
    dataSet, features = createDataSet()
    featLabels = []  # 存储选择的最优特征
    myTree = createTree(dataSet, features, featLabels)
    storeTree(myTree, 'classifierStorage.txt')
    storeTree(featLabels, 'featLabelsStorage.txt')  # 顺便借用这个函数
