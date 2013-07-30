#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.move(300, 300)
        self.setWindowTitle("Buttons")
        self.initUI()

    def initUI(self):
        button1 = QtGui.QPushButton("Button")
        button2 = QtGui.QPushButton("Button")
        button3 = QtGui.QPushButton("Button")
        button4 = QtGui.QPushButton("Button")
        button5 = QtGui.QPushButton("Button")
        button6 = QtGui.QPushButton("Button")

        grid = QtGui.QGridLayout()
        grid.addWidget(button1, 0, 0)
        grid.addWidget(button2, 0, 1)
        grid.addWidget(button3, 0, 2)
        grid.addWidget(button4, 1, 0)
        grid.addWidget(button5, 1, 1)
        grid.addWidget(button6, 1, 2)

        self.setLayout(grid)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())