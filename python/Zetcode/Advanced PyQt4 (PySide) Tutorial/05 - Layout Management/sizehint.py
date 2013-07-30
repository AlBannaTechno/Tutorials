#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class MyButton(QtGui.QPushButton):

    def __init__(self, text, parent, size):
        QtGui.QPushButton.__init__(self, text, parent)
        self.size = size

    def sizeHint(self):
        return self.size


class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 300, 230)
        self.setWindowTitle("Size Hints")
        self.initUI()

    def initUI(self):
        button1 = QtGui.QPushButton("Button", self)
        button1.move(20, 50)

        button2 = MyButton("Button", self, QtCore.QSize(140, 47))
        button2.move(150, 50)

        button3 = MyButton("Button", self, QtCore.QSize(150, 60))
        button3.move(50, 150)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())