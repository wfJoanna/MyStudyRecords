from flask import Flask, render_template

app = Flask(__name__)


@app.route('/')
def index():
    return "<h1>hello<h1>"


@app.route('/user/<name>')
def user(name):
    return render_template('bootstrap.html', name=name)


if __name__ == '__main__':
    app.run()
