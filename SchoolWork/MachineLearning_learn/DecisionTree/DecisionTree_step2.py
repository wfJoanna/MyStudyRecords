import pickle

"""
直接调用之前生成并保存好的决策树
"""


def grabTree(filename):
    fr = open(filename, 'rb')
    return pickle.load(fr)


def classify(inputTree, featLabels, testVec):
    A = next(iter(inputTree))
    # 用了iter()才能用next()
    # next()就是每执行一次就返回下一个值（这里的话就是返回字典的键）
    B = inputTree[A]  # A每次递归都是决策树的结点，B每次递归都是树枝
    featIndex = featLabels.index(A)
    for key in B.keys():
        if testVec[featIndex] == key:
            if type(B[key]).__name__ == 'dict':  # 意思就是如果还有下一个结点的话，即不是叶结点的话
                classLabel = classify(B[key], featLabels, testVec)
            else:
                classLabel = B[key]
    return classLabel


if __name__ == '__main__':
    myTree = grabTree('classifierStorage.txt')
    featLabels = grabTree('featLabelsStorage.txt')
    testVec = [0, 1]
    # 因为之前生成的决策树只需要两个问题就可到达叶结点，所以这里也只需要两个特征就行了
    # 这里的数据代表没有房子，但是有工作
    result = classify(myTree, featLabels, testVec)
    if result == 'yes':
        print('放贷')
    if result == 'no':
        print('不放贷')
