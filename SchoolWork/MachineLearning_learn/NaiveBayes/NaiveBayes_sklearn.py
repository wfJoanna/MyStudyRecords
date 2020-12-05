# -*- coding: UTF-8 -*-
from sklearn.naive_bayes import MultinomialNB
import matplotlib.pyplot as plt
import os
import random
import jieba


def TextProcessing(folder_path, test_size):  # test_size是测试集占比
    folder_list = os.listdir(folder_path)  # os.listdir()方法用于返回指定的文件夹包含的文件或文件夹的名字的列表
    data_list = []
    class_list = []

    for folder in folder_list:
        new_folder_path = os.path.join(folder_path, folder)  # 生成子文件夹的路径
        files = os.listdir(new_folder_path)

        j = 1
        for file in files:
            if j > 100:  # 限定每类txt样本数最多100个
                break
            with open(os.path.join(new_folder_path, file), 'r', encoding='utf-8') as f:
                raw = f.read()  # 读取整个文件

            word_cut = jieba.cut(raw, cut_all=False)  # jieba.cut()的精简模式。返回一个可迭代的generator
            word_list = list(word_cut)  # generator转换为list

            data_list.append(word_list)
            # 提醒一下，append()括号里是啥他就添加啥，括号里是个字符串那就添加字符串为元素，括号里是个列表那就添加列表为元素
            # 用extend()的话，括号里只能是列表，然后把列表里的元素添加到列表中，而不是把列表添加到列表中
            class_list.append(folder)
            j += 1

    data_class_list = list(zip(data_list, class_list))  # zip()就是一一对应成元组，然后再用list()弄成元组的列表
    random.shuffle(data_class_list)  # random.shuffle()方法将序列的所有元素随机排序
    index = int(len(data_class_list) * test_size) + 1  # index前面是测试集，后面是训练集
    train_list = data_class_list[index:]  # 训练集
    test_list = data_class_list[:index]  # 测试集
    train_data_list, train_class_list = zip(*train_list)  # zip()加了*就相当于解压，有点难以解释所以你自己搜吧
    test_data_list, test_class_list = zip(*test_list)
    # 之所以要打包后又解压，是因为要打乱顺序，然后直接切割

    all_words_dict = {}  # 用来统计训练集词频
    for word_list in train_data_list:
        for word in word_list:
            if word in all_words_dict.keys():
                all_words_dict[word] += 1
            else:
                all_words_dict[word] = 1

    all_words_tuple_list = sorted(all_words_dict.items(), key=lambda f: f[1], reverse=True)  # 根据键的值倒序排序
    all_words_list, all_words_nums = zip(*all_words_tuple_list)
    all_words_list = list(all_words_list)
    return all_words_list, train_data_list, test_data_list, train_class_list, test_class_list


def MakeWordsSet(words_file):  # 读取文件并去重
    words_set = set()
    with open(words_file, 'r', encoding='utf-8') as f:
        for line in f.readlines():
            word = line.strip()  # strip()方法用于移除字符串头尾的指定的字符（默认为空格或换行符）
            if len(word) > 0:  # 如果有文本，则添加到words_set中
                words_set.add(word)
    return words_set


def TextFeatures(train_data_list, test_data_list, feature_words): #根据feature_words将文本向量化
    def text_features(text, feature_words):  # 出现在特征集中，则置1
        text_words = set(text)
        features = [1 if word in text_words else 0 for word in feature_words]
        return features

    train_feature_list = [text_features(text, feature_words) for text in train_data_list]
    test_feature_list = [text_features(text, feature_words) for text in test_data_list]
    return train_feature_list, test_feature_list


def words_dict(all_words_list, deleteN, stopwords_set):  # 这个函数用来确定特征词。删除词频最高的deleteN个词。stopwords_set是指定的结束语
    feature_words = []  # 特征列表
    n = 1
    for t in range(deleteN, len(all_words_list), 1):  # range()三个参数自己去搜各自是什么意思吧
        if n > 1000:  # feature_words的维度限定为1000以内
            break
        if not all_words_list[t].isdigit() and all_words_list[t] not in stopwords_set and 1 < len(
                all_words_list[t]) < 5:  # 如果这个词不是数字，并且不是指定的结束语，并且单词长度大于1小于5，那么这个词就可以作为特征词
            feature_words.append(all_words_list[t])
        n += 1
    return feature_words


def TextClassifier(train_feature_list, test_feature_list, train_class_list, test_class_list): # 新闻分类器
    # 在scikit-learn中，一共有3个朴素贝叶斯的分类算法类
    # 分别是GaussianNB，MultinomialNB和BernoulliNB
    # 其中GaussianNB就是先验为高斯分布的朴素贝叶斯，MultinomialNB就是先验为多项式分布的朴素贝叶斯，而BernoulliNB就是先验为伯努利分布的朴素贝叶斯
    classifier = MultinomialNB().fit(train_feature_list, train_class_list)
    test_accuracy = classifier.score(test_feature_list, test_class_list) # 得到分类器准确率
    return test_accuracy


if __name__ == '__main__':
    folder_path = './SogouC/Sample'
    all_words_list, train_data_list, test_data_list, train_class_list, test_class_list = TextProcessing(folder_path,0.2)

    stopwords_file = './stopwords_cn.txt'  # 这里面是一些对于新闻分类无影响的词，需要去掉（当然为了降低对新闻分类无关痛痒的词对分类结果的影响，我们还要去掉高频词）
    stopwords_set = MakeWordsSet(stopwords_file)

    test_accuracy_list = []
    deleteNs = range(0, 1000, 20)  # 0 20 40 60 ... 980
    for deleteN in deleteNs:
        feature_words = words_dict(all_words_list, deleteN, stopwords_set)
        train_feature_list, test_feature_list = TextFeatures(train_data_list, test_data_list, feature_words)
        test_accuracy = TextClassifier(train_feature_list, test_feature_list, train_class_list, test_class_list)
        test_accuracy_list.append(test_accuracy)

    plt.figure()
    plt.plot(deleteNs, test_accuracy_list)
    plt.title('Relationship of deleteNs and test_accuracy')
    plt.xlabel('deleteNs')
    plt.ylabel('test_accuracy')
    plt.show()
    # 每次运行程序，绘制的图形可能不尽相同，我们可以通过多次测试，来决定这个deleteN的取值，这样就可以顺利构建出用于新闻分类的朴素贝叶斯分类器了

    # 假设取定deleteN为450
    test_accuracy_list = []
    feature_words = words_dict(all_words_list, 450, stopwords_set)
    train_feature_list, test_feature_list = TextFeatures(train_data_list, test_data_list, feature_words)
    test_accuracy = TextClassifier(train_feature_list, test_feature_list, train_class_list, test_class_list)
    test_accuracy_list.append(test_accuracy)
    ave = lambda c: sum(c) / len(c)
    print(ave(test_accuracy_list)) # 得到当deleteN=450时分类器的准确率