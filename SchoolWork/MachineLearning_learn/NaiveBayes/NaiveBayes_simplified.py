import numpy as np
# from functools import reduce


def loadDataSet():
    postingList = [['my', 'dog', 'has', 'flea', 'problems', 'help', 'please'],
                   ['maybe', 'not', 'take', 'him', 'to', 'dog', 'park', 'stupid'],
                   ['my', 'dalmation', 'is', 'so', 'cute', 'I', 'love', 'him'],
                   ['stop', 'posting', 'stupid', 'worthless', 'garbage'],
                   ['mr', 'licks', 'ate', 'my', 'steak', 'how', 'to', 'stop', 'him'],
                   ['quit', 'buying', 'worthless', 'dog', 'food', 'stupid']]
    classVec = [0, 1, 0, 1, 0, 1]  # 类别标签向量，1代表侮辱性词汇，0代表不是
    return postingList, classVec


def setOfWords2Vec(vocabList, inputSet):  # 根据vocabList词汇表，将inputSet向量化，向量的每个元素为1或0
    returnVec = [0] * len(vocabList)  # 创建一个其中所含元素都为0的向量。注意这个列表的长度是vocabList的长度
    for word in inputSet:
        if word in vocabList:
            returnVec[vocabList.index(word)] = 1
        else:
            print("the word: %s is not in my Vocabulary!" % word)  # 我感觉不太可能出现这种情况
    return returnVec


def createVocabList(dataSet):  # 将实验样本整理成不重复的词汇表，是出现过的所有单词的集合
    vocabSet = set([])  # 创建一个空集合，可以使元素不重复
    for document in dataSet:
        vocabSet = vocabSet | set(document)  # 取并集
    return list(vocabSet)


# def trainNB0(trainMatrix, trainCategory):  # 朴素贝叶斯分类器训练函数
#     numTrainDocs = len(trainMatrix)  # 计算训练的文档数目（我们把每一句称为一个文档）
#     numWords = len(trainMatrix[0])  # 计算所有文档所用的词汇数
#     pAbusive = sum(trainCategory) / float(numTrainDocs)  # 文档属于侮辱类的概率
#     p0Num = np.zeros(numWords)
#     p1Num = np.zeros(numWords)
#     p0Denom = 0.0
#     p1Denom = 0.0
#     for i in range(numTrainDocs):
#         if trainCategory[i] == 1:
#             p1Num += trainMatrix[i]  # 统计侮辱类文档的单词出现次数
#             p1Denom += sum(trainMatrix[i])  # 统计侮辱类文档所用的单词数量
#         else:
#             p0Num += trainMatrix[i]
#             p0Denom += sum(trainMatrix[i])
#     p1Vect = p1Num / p1Denom  # 比如p1Vect[0]就是p(w0|1)，即myVocabList第一个单词在侮辱类中出现的频率
#     p0Vect = p0Num / p0Denom
#     return p0Vect, p1Vect, pAbusive  # 返回属于侮辱类的条件概率数组，属于非侮辱类的条件概率数组，文档属于侮辱类的概率

# 上面这个不能用，原因详见JackCui文章，我懒得写了
# 需要在上面的基础上做一些调整

def trainNB0(trainMatrix, trainCategory):
    numTrainDocs = len(trainMatrix)
    numWords = len(trainMatrix[0])
    pAbusive = sum(trainCategory) / float(numTrainDocs)
    p0Num = np.ones(numWords)
    p1Num = np.ones(numWords)  # 创建numpy.ones数组,词条出现数初始化为1，拉普拉斯平滑
    p0Denom = 2.0
    p1Denom = 2.0  # 分母初始化为2,拉普拉斯平滑
    for i in range(numTrainDocs):
        if trainCategory[i] == 1:
            p1Num += trainMatrix[i]
            p1Denom += sum(trainMatrix[i])
        else:
            p0Num += trainMatrix[i]
            p0Denom += sum(trainMatrix[i])
    p1Vect = np.log(p1Num / p1Denom)  # 取对数，防止下溢出
    p0Vect = np.log(p0Num / p0Denom)
    return p0Vect, p1Vect, pAbusive


# def classifyNB(vec2Classify, p0Vec, p1Vec, pClass1):  # 朴素贝叶斯分类器分类函数
#     p1 = reduce(lambda x, y: x * y, vec2Classify * p1Vec) * pClass1
#     p0 = reduce(lambda x, y: x * y, vec2Classify * p0Vec) * (1.0 - pClass1)
#     # 自己查reduce()的功能吧。最后的结果就是序列的元素累积相乘，自己看公式吧（是省略了的，因为我们只需要比大小）
#     # 因为这里vec2Classify、p0Vec、p1Vec都是np.array()产生的ndarray数组，不是普通的list（打印出来你会发现，前者元素之间没有逗号，后者元素之间有逗号）
#     # 所以这里可以相乘，而普通的列表是没法直接相乘的。乘的法则是对应位置两个元素相乘，就这么简单。比如[1 2 3]*[4 5 6]=[4 10 18]
#     if p1 > p0:
#         return 1
#     else:
#         return 0

# 因为对trainNB0进行了调整，所以上面这个也不能用了，必须也做一下调整

def classifyNB(vec2Classify, p0Vec, p1Vec, pClass1):
    p1 = sum(vec2Classify * p1Vec) + np.log(pClass1)  # 对应元素相乘。logA * B = logA + logB，所以这里加上log(pClass1)
    p0 = sum(vec2Classify * p0Vec) + np.log(1.0 - pClass1)
    if p1 > p0:
        return 1
    else:
        return 0


def testingNB():
    postingList, classVec = loadDataSet()
    myVocabList = createVocabList(postingList)
    print('myVocabList:\n', myVocabList)
    trainMat = []
    for postingDoc in postingList:
        trainMat.append(setOfWords2Vec(myVocabList, postingDoc))
    print('trainMat:\n', trainMat)
    p0V, p1V, pAb = trainNB0(np.array(trainMat), np.array(classVec))

    testEntry = ['love', 'my', 'dalmation']  # 测试样本1
    thisDoc = np.array(setOfWords2Vec(myVocabList, testEntry))  # 看样本1中出现了myVocabList中的哪些词
    if classifyNB(thisDoc, p0V, p1V, pAb):
        print(testEntry, '属于侮辱类')
    else:
        print(testEntry, '属于非侮辱类')

    testEntry = ['stupid', 'garbage']  # 测试样本2
    thisDoc = np.array(setOfWords2Vec(myVocabList, testEntry))
    if classifyNB(thisDoc, p0V, p1V, pAb):
        print(testEntry, '属于侮辱类')
    else:
        print(testEntry, '属于非侮辱类')


if __name__ == '__main__':
    testingNB()
