from flask import Flask

app = Flask(__name__)

@app.route('/projects/')
def projects():
    return 'The projects page'

@app.route('/about')
def about():
    return 'The about page'
