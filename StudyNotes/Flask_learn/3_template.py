from flask import Flask, render_template

app = Flask(__name__)


@app.route('/')
def index():
    return render_template('index.html')  # 默认情况下，flask在应用目录的templates子目录寻找模板


@app.route('/user/<name>')
def user(name):
    return render_template('user.html', name=name)  # 等号左边的name是模板中使用的占位符，等号右边的name是当前作用域的变量


@app.route('/jinja/<name>')
def jinja(name):
    return render_template('jinja.html', user=name)


if __name__ == '__main__':
    app.run()
