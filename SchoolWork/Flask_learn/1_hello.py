from flask import Flask

app = Flask(__name__)


@app.route('/')
def index():
    return '<h1>Hello world!<h1>'


# app.route()叫装饰器
# index()叫视图函数

# 也可以这样：（我不喜欢这种方式）
# def index():
#     return '<h1>Hello world!<h1>'
# app.add_url_rule(‘/’, ‘index’, index)  # 这三个参数分别表示URL、端点名、视图函数


@app.route('/user/<name>')
def user(name):
    return '<h1>Hello, {}!<h1>'.format(name)


if __name__ == '__main__':
    app.run()
