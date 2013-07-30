#!/usr/bin/env python
# -*- encoding: utf-8 -*-
from bottle import Bottle, run, static_file, request


app = Bottle()

@app.route('/')
@app.route('/hello/<name>')
def greet(name='Stranger'):
    return 'Hello {0}, how are you?'.format(name)

@app.route('/hello')
def hello():
    return 'Hello, World!'

@app.route('/wiki/<pagename>')
def show_wiki_page(pagename):
    return 'Sorry, {0} page does not exist. Why not create it?'.format(pagename)

@app.route('/<action>/<user>')
def user_api(action, user):
    return 'Hello {0}! You just requested {1} be performed!'.format(user, action)

@app.route('/object/<id:int>')
def callback(id):
    assert isinstance(id, int)

@app.route('/show/<name:re:[a-z]+>')
def callback(name):
    assert name.isalpha()

@app.route('/static/<path:path>')
def callback(path):
#    return static_file(path, ...)
    pass

@app.route('/login')
def login_form():
    return '''<form method="POST">
                <input name="name" type="text" />
                <input name="password" type="password" />
                <input name="submit" type="submit" />
              </form>'''

@app.route('/login', method='POST')
def login_submit():
    name = request.forms.get('name')
    password = request.forms.get('password')
    if check_login(name, password):
        return '<p>Your login was correct</p>'
    else:
        return '<p>Login failed</p>'

def check_login(name, password):
    if name == 'admin' and password == 'admin':
        return True
    else:
        return False


if __name__ == '__main__':
    run(app, host='localhost', port=8080)
