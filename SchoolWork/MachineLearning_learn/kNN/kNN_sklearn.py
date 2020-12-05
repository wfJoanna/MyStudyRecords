import numpy as np
import operator
from os import listdir
from sklearn.neighbors import KNeighborsClassifier as kNN


def img2vector(filename):  # 数字图片是32*32的二进制图像，为了方便计算，我们把它转换成1*1024的向量
    returnVect = np.zeros((1, 1024))
    fr = open(filename)
    for i in range(32):
        lineStr = fr.readline()  # 读一行数据
        for j in range(32):
            returnVect[0, 32 * i + j] = int(lineStr[j])
    return returnVect


def handwritingClassTest():
    hwLabels = []
    trainingFileList = listdir('trainingDigits')  # 返回trainingDigits目录下的文件名组成的列表
    m = len(trainingFileList)
    trainingMat = np.zeros((m, 1024))

    for i in range(m):
        fileNameStr = trainingFileList[i]
        classNumber = int(fileNameStr.split('_')[0])  # 因为文件名很特殊，格式为：数字的值_该数字的样本序号
        hwLabels.append(classNumber)
        trainingMat[i, :] = img2vector('trainingDigits/%s' % (fileNameStr))

    # 以上是准备数据的过程。每个图像的二进制组成数字和对应的标签都分别放入了hwLabels和trainingMat

    neigh = kNN(n_neighbors=3, algorithm='auto')  # 构建kNN分类器
    neigh.fit(trainingMat, hwLabels)  # 拟合模型

    testFileList = listdir('testDigits')
    errorCount = 0.0
    mTest = len(testFileList)

    for i in range(mTest):
        fileNameStr = testFileList[i]
        classNumber = int(fileNameStr.split('_')[0])  # 获得正确的数字
        vectorUnderTest = img2vector('testDigits/%s' % (fileNameStr))
        classifierResult = neigh.predict(vectorUnderTest)  # 获得预测的结果
        print("分类返回结果为%d\t真实结果为%d" % (classifierResult, classNumber))
        if (classifierResult != classNumber):
            errorCount += 1.0
    print("总共错了%d个数据\n错误率为%f%%" % (errorCount, errorCount / mTest * 100))


if __name__ == '__main__':
    handwritingClassTest()
