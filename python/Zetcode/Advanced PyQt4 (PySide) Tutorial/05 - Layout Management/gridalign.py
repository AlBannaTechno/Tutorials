#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 350, 150)
        self.setWindowTitle("Alignments")
        self.initUI()

    def initUI(self):
        button1 = QtGui.QPushButton("Left")
        button2 = QtGui.QPushButton("Center")
        button3 = QtGui.QPushButton("Right")
        button4 = QtGui.QPushButton("Stretch")

        grid = QtGui.QGridLayout()
        grid.addWidget(button1, 0, 0, QtCore.Qt.AlignLeft)
        grid.addWidget(button2, 1, 0, QtCore.Qt.AlignCenter)
        grid.addWidget(button3, 2, 0, QtCore.Qt.AlignRight)
        grid.addWidget(button4, 3, 0)

        self.setLayout(grid)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())