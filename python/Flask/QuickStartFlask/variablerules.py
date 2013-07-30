from flask import Flask

app = Flask(__name__)

@app.route('/user/<username>')
def show_user_profile(username):
    # Show the user profile for that user
    return 'User {0}'.format(username)

@app.route('/post/<int:post_id>')
def show_post(post_id):
    # Show the post with given id, the id is an integer
    return 'Post {0}'.format(post_id)


if __name__ == '__main__':
    app.run()
