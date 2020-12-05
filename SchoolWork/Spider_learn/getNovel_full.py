# -*- coding:UTF-8 -*-

from bs4 import BeautifulSoup
import requests, sys


class downloader(object):

    def __init__(self):
        self.server = 'http://www.biqukan.com/'
        self.target = 'http://www.biqukan.com/1_1094/'
        self.names = []  # 存放章节名
        self.urls = []  # 存放章节链接
        self.nums = 0  # 章节数

    def get_download_url(self):
        req = requests.get(url=self.target)
        req.encoding = 'GBK'
        html = req.text
        div_bs = BeautifulSoup(html, "html.parser")
        div = div_bs.find_all('div', class_='listmain')
        a_bs = BeautifulSoup(str(div[0]), "html.parser")
        a = a_bs.find_all('a')
        self.nums = len(a[12:])  # 剔除不必要的章节，并统计章节数
        for each in a[12:]:
            self.names.append(each.string)
            self.urls.append(self.server + each.get('href'))

    def get_contents(self, target):
        req = requests.get(url=target)
        req.encoding = 'GBK'
        html = req.text
        bs = BeautifulSoup(html, "html.parser")
        texts = bs.find_all('div', class_='showtxt')
        texts = texts[0].text.replace('\xa0' * 4, '\n\n')
        return texts

    def writer(self, name, path, text):
        with open(path, 'a', encoding='utf-8') as f:
            f.write(name + '\n')
            f.writelines(text)
            f.write('\n\n')


if __name__ == "__main__":
    dl = downloader()
    dl.get_download_url()
    print('《一念永恒》开始下载：')
    for i in range(dl.nums):
        dl.writer(dl.names[i], '一念永恒.txt', dl.get_contents(dl.urls[i]))
        sys.stdout.write("  已下载:%.3f%%" % float(i / dl.nums * 100) + '\r')  # 这个'\r'是回到本行开头，但和print配合的话很不好用，在各个终端会有不同结果
        sys.stdout.flush()  # 注意啦！这两行是一对，要在cmd运行才能看到结果，在pycharm运行看不到结果（不过在pycharm的Terminal可以看到）
    print('《一念永恒》下载完成')
