#!/usr/bin/env python
# -*- encoding: utf-8 -*-

import random
import sys
from PySide import QtCore, QtGui


WIDTH = 300
HEIGHT = 270
DOT_SIZE = 10
ALL_DOTS = WIDTH * HEIGHT / (DOT_SIZE * DOT_SIZE)
RAND_POS = 26
DELAY = 140

x = [0] * ALL_DOTS
y = [0] * ALL_DOTS


class Board(QtGui.QWidget):
    def __init__(self):
        QtGui.QWidget.__init__(self)
        
        self.setFocusPolicy(QtCore.Qt.StrongFocus)
        self.initGame()
        
    def initGame(self):
        self.left = False
        self.right = True
        self.up = False
        self.down = False
        self.in_game = True
        self.dots = 3
        
        for i in range(self.dots):
            x[i] = 50 - i * 10
            y[i] = 50
            
        try:
            self.ball = QtGui.QImage('./dot.png')
            self.apple = QtGui.QImage('./apple.png')
            self.head = QtGui.QImage('./head.png')
        except Exception as error:
            print error
            sys.exit(1)
        
        self.locateApple()
        self.timer = QtCore.QBasicTimer()
        self.timer.start(DELAY, self)
        
    def timerEvent(self, event):
        if self.in_game:
            self.checkApple()
            self.checkCollision()
            self.move()
        else:
            self.timer.stop()
            
        self.repaint()
        
    def paintEvent(self, event):
        QtGui.QWidget.paintEvent(self, event)
        
        painter = QtGui.QPainter()
        painter.begin(self)
        
        painter.setBrush(QtGui.QColor(0, 0, 0, 255))
        painter.drawRect(0, 0, self.width(), self.height())
        
        if self.in_game:
            self.drawObjects(painter)
        else:
            self.gameOver(painter)
            
        painter.end()
        
    def drawObjects(self, painter):
        painter.drawImage(self.apple_x, self.apple_y, self.apple)

        for z in range(self.dots):
            if z == 0:
                painter.drawImage(x[z], y[z], self.head)
            else:
                painter.drawImage(x[z], y[z], self.ball)

    def gameOver(self, painter):
        msg = 'Game Over'
        small = QtGui.QFont('Helvetica', 12, QtGui.QFont.Bold)
        metrics = QtGui.QFontMetrics(small)
        text_width = metrics.width(msg)

        painter.setPen(QtGui.QColor(255, 255, 255))
        painter.setFont(small)
        painter.translate(QtCore.QPoint(self.width() / 2, self.height() / 2))
        painter.drawText(-text_width/2, 0, msg)

    def checkApple(self):
        if x[0] == self.apple_x and y[0] == self.apple_y:
            self.dots += 1
            self.locateApple()

    def move(self):
        z = self.dots
        while z > 0:
            x[z] = x[(z - 1)]
            y[z] = y[(z - 1)]
            z -= 1

        if self.left:
            x[0] -= DOT_SIZE

        if self.right:
            x[0] += DOT_SIZE

        if self.up:
            y[0] -= DOT_SIZE

        if self.down:
            y[0] += DOT_SIZE

    def checkCollision(self):
        z = self.dots

        while z > 0:
            if z > 4 and x[0] == x[z] and y[0] == y[z]:
                self.in_game = False
            z -= 1

        if y[0] > HEIGHT - DOT_SIZE:
            self.in_game = False

        if y[0] < 0:
            self.in_game = False

        if x[0] > WIDTH - DOT_SIZE:
            self.in_game = False

        if x[0] < 0:
            self.in_game = False

    def locateApple(self):
        rand = random.randint(0, RAND_POS)
        self.apple_x = rand * DOT_SIZE
        rand = random.randint(0, RAND_POS)
        self.apple_y = rand * DOT_SIZE

    def keyPressEvent(self, event):
        key = event.key()
        if key == QtCore.Qt.Key_Left and not self.right:
            self.left = True
            self.up = False
            self.down = False

        if key == QtCore.Qt.Key_Right and not self.left:
            self.right = True
            self.up = False
            self.down = False

        if key == QtCore.Qt.Key_Up and not self.down:
            self.up = True
            self.right = False
            self.left = False

        if key == QtCore.Qt.Key_Down and not self.up:
            self.down = True
            self.right = False
            self.left = False


class Nibbles(QtGui.QMainWindow):
    def __init__(self):
        QtGui.QMainWindow.__init__(self)

        self.setWindowTitle('Nibbles')
        self.resize(WIDTH, HEIGHT)
        self.setCentralWidget(Board())
        self.move(300, 300)


if __name__ == '__main__':
    import sys

    app = QtGui.QApplication([])
    root = Nibbles()
    root.show()

    sys.exit(app.exec_())