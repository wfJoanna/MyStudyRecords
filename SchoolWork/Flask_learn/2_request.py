from flask import Flask
from flask import request

app = Flask(__name__)


@app.route('/')
def index():
    userAgent = request.headers.get('User-Agent')
    return '<h1>Your browser is {}</h1>'.format(userAgent)


@app.route('/request')  # 路径名可以随便取
def reques():  # 但是函数名不能。如果这里函数名取做request，整个就会报错
    userAgent = request.headers.get('User-Agent')
    return '<p>Your browser is {}</p>'.format(userAgent)


if __name__ == '__main__':
    app.run()
