# -*- coding: UTF-8 -*-
import re
import numpy as np
import random


def textParse(bigString):
    listOfTokens = re.split(r'\W+', bigString)
    # 将特殊符号作为切分标志进行字符串切分，即非字母、非数字
    # 自己查re.split()方法吧
    return [tok.lower() for tok in listOfTokens if len(tok) > 2]
    # lower() 方法转换字符串中所有大写字符为小写
    # 单个字母和2个字母的单词没有添加进返回的数组


def createVocabList(dataSet):
    vocabSet = set([])
    for document in dataSet:
        vocabSet = vocabSet | set(document)
    return list(vocabSet)


def setOfWords2Vec(vocabList, inputSet):
    returnVec = [0] * len(vocabList)
    for word in inputSet:
        if word in vocabList:
            returnVec[vocabList.index(word)] = 1
        else:
            print("the word: %s is not in my Vocabulary!" % word)
    return returnVec


def trainNB0(trainMatrix, trainCategory):
    numTrainDocs = len(trainMatrix)
    numWords = len(trainMatrix[0])
    pAbusive = sum(trainCategory) / float(numTrainDocs)
    p0Num = np.ones(numWords)
    p1Num = np.ones(numWords)
    p0Denom = 2.0
    p1Denom = 2.0
    for i in range(numTrainDocs):
        if trainCategory[i] == 1:
            p1Num += trainMatrix[i]
            p1Denom += sum(trainMatrix[i])
        else:
            p0Num += trainMatrix[i]
            p0Denom += sum(trainMatrix[i])
    p1Vect = np.log(p1Num / p1Denom)
    p0Vect = np.log(p0Num / p0Denom)
    return p0Vect, p1Vect, pAbusive


def classifyNB(vec2Classify, p0Vec, p1Vec, pClass1):
    p1 = sum(vec2Classify * p1Vec) + np.log(pClass1)
    p0 = sum(vec2Classify * p0Vec) + np.log(1.0 - pClass1)
    if p1 > p0:
        return 1
    else:
        return 0


def spamTest():
    docList = []
    classList = []
    fullText = []
    for i in range(1, 26):  # 遍历25个txt文件
        wordList = textParse(open('email/spam/%d.txt' % i, 'r').read())  # spam文件下的txt文件为垃圾邮件
        docList.append(wordList)
        classList.append(1)
        wordList = textParse(open('email/ham/%d.txt' % i, 'r').read())  # read()是从文件读取指定的字节数，默认为读取整个文件
        docList.append(wordList)
        classList.append(0)  # 这样下来docList和classList一一对应
    vocabList = createVocabList(docList)  # 删除重复的单词得到vocabList。但是vocabList和classList没有一一对应的关系

    trainingSet = list(range(50))  # 存储训练集索引值的列表
    testSet = []  # 存储测试集索引值的列表
    for i in range(10):  # 从50个邮件中，随机挑选出40个作为训练集,10个做测试集
        randIndex = int(random.uniform(0, len(trainingSet)))
        testSet.append(trainingSet[randIndex])
        del (trainingSet[randIndex])

    trainMat = []
    trainClasses = []
    for docIndex in trainingSet:
        trainMat.append(setOfWords2Vec(vocabList, docList[docIndex]))
        trainClasses.append(classList[docIndex])
    p0V, p1V, pSpam = trainNB0(np.array(trainMat), np.array(trainClasses))  # 训练朴素贝叶斯模型

    errorCount = 0  # 错误分类计数
    for docIndex in testSet:
        wordVector = setOfWords2Vec(vocabList, docList[docIndex])
        if classifyNB(np.array(wordVector), p0V, p1V, pSpam) != classList[docIndex]:  # 如果分类错误
            errorCount += 1  # 错误计数加1
            print("分类错误的测试集：", docList[docIndex])
    print('错误率：%.2f%%' % (float(errorCount) / len(testSet) * 100))


if __name__ == '__main__':
    spamTest()
