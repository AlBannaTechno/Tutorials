#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.move(300, 300)
        self.setWindowTitle("Spanning")
        self.initUI()

    def initUI(self):
        grid = QtGui.QGridLayout()
        grid.addWidget(QtGui.QLineEdit(), 0, 0)
        grid.addWidget(QtGui.QLineEdit(), 0, 1)
        grid.addWidget(QtGui.QLineEdit(), 0, 2)
        grid.addWidget(QtGui.QLineEdit(), 0, 3)

        grid.addWidget(QtGui.QLineEdit(), 1, 0, 1, 2)
        grid.addWidget(QtGui.QLineEdit(), 2, 0, 1, 3)
        grid.addWidget(QtGui.QLineEdit(), 3, 0, 1, 4)

        self.setLayout(grid)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())