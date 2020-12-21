# -*- coding:UTF-8 -*-
from bs4 import BeautifulSoup
import requests

if __name__ == "__main__":
    target = 'https://www.biqukan.com/99976_99976488/63984700.html'
    req = requests.get(url=target)
    html = req.text  # 获取到html文档

    bs = BeautifulSoup(html, "html.parser")  # BeautifulSoup用来解析HTML信息，提取我们感兴趣的内容
    texts = bs.find_all('div', class_='showtxt')  # 获得了class为showtxt的div内容
    print(texts[0].text.replace('\xa0' * 4, '\n\n'))
    # 替换空格为换行符
    # 同时因为是texts[0].text，所以不会有<br><div>等标签
    # 之所以是texts[0]，是因为texts是一个只有一个元素的数组
