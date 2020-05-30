# -*- coding: UTF-8 -*-
import numpy as np
import operator

def createDataSet():
    group = np.array([[1,101],[5,89],[108,5],[115,8]]) #四组二维特征
    labels = ['爱情片','爱情片','动作片','动作片'] #四组特征的标签
    return group, labels

def classify0(inX, dataSet, labels, k): #kNN分类
    dataSetSize = dataSet.shape[0] #numpy函数shape[0]返回dataSet的行数
    diffMat = np.tile(inX, (dataSetSize, 1)) - dataSet #tile是平铺的意思。np.tile()不懂就自行百度吧
    sqDiffMat = diffMat**2 #自个儿复习numpy去吧。b**2的意思是二维数组b的各个元素都变成自己的平方
    sqDistances = sqDiffMat.sum(axis=1)
    distances = sqDistances**0.5 #到这一步就恰好是距离公式的结果了
    
    sortedDistIndices = distances.argsort() #返回元素从小到大排序后的索引值。arg就是有点反函数的意思
    classCount = {} #空字典
    for i in range(k):
        voteIlabel = labels[sortedDistIndices[i]] #得到的是对应的标签，也就是电影类别
        classCount[voteIlabel] = classCount.get(voteIlabel,0) + 1 #dict.get(key,default=None)。字典的get()方法,返回指定键的值,如果值不在字典中返回默认值

    sortedClassCount = sorted(classCount.items(),key=operator.itemgetter(1),reverse=True) #自行查operator模块和sorted()吧
    #key=operator.itemgetter(1)根据字典的值进行排序，key=operator.itemgetter(0)根据字典的键进行排序
    #reverse降序排序字典
    return sortedClassCount[0][0] #因为得到的sortedClassCount好像是个二维数组

if __name__ == '__main__':
    group, labels = createDataSet() #创建数据集
    test = [101,20] #测试集
    test_class = classify0(test, group, labels, 3)
    print(test_class)