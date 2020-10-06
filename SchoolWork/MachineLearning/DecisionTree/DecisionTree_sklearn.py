from sklearn.preprocessing import LabelEncoder
from sklearn import tree
import pandas as pd

if __name__ == '__main__':
    fr = open('lenses.txt')
    lenses = [inst.strip().split('\t') for inst in fr.readlines()]  # 这是一个二维数组，里面是分割好的每行每列数据

    lensesLabels = []  # 提取每组数据的标签，保存在列表里。是有重复的哦
    for each in lenses:
        lensesLabels.append(each[-1])

    lensesFeatures = ['age', 'prescript', 'astigmatic', 'tearRate']
    lenses_list = []  # 临时中介
    lenses_dict = {}  # 临时中介
    for each_feature in lensesFeatures:
        for each in lenses:
            lenses_list.append(each[lensesFeatures.index(each_feature)])
        lenses_dict[each_feature] = lenses_list
        lenses_list = []  # 最终就是各个特征对应他的所有数据
    lenses_pd = pd.DataFrame(lenses_dict)  # 生成pandas.DataFrame

    le = LabelEncoder()
    for col in lenses_pd.columns:
        lenses_pd[col] = le.fit_transform(lenses_pd[col])
    print(lenses_pd)
    # 序列化，将字符串转化为0、1、2这样的数字。上面这四行会用就行
    # 据我观察，是按大小排的，比如'no'<'yes'，所以'no'变为0，'yes'变为1

    clf = tree.DecisionTreeClassifier(max_depth=4)  # max_depth限制决策树最深层数，如果模型样本量多，特征也多的情况下，推荐限制这个最大深度
    clf = clf.fit(lenses_pd.values.tolist(), lensesLabels)  # 上面两大段都是为了契合这里要求的数据格式
    print(lenses_pd.values.tolist())
    print(clf.predict([[1, 1, 1, 0]]))
