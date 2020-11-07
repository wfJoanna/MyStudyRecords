from bs4 import BeautifulSoup
import requests

if __name__ == "__main__":
    server = 'https://www.biqukan.com/'
    target = 'https://www.biqukan.com/99976_99976488/'
    req = requests.get(url=target)
    req.encoding = 'GBK'  # 因为爬这个的时候，莫名其妙中文乱码，所以这个爬虫结果需要用BGK编码一下
    html = req.text

    div_bs = BeautifulSoup(html,"html.parser")
    div = div_bs.find_all('div', class_='listmain')
    a_bs = BeautifulSoup(str(div[0]),"html.parser")  # 用str的原因是BeautifulSoup()只接收字符串参数
    a = a_bs.find_all('a')
    for each in a:
        print(each.string, server + each.get('href'))  # 你可以打印a看看，就知道为什么这样就可以打印出我们想要的东西
