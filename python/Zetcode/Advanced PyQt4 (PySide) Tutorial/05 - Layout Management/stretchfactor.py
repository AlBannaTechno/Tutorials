#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.move(300, 300)
        self.setWindowTitle("Stretch Factor")
        self.initUI()

    def initUI(self):
        b1 = QtGui.QPushButton("Button")
        b2 = QtGui.QPushButton("Button")
        b3 = QtGui.QPushButton("Button")

        hbox = QtGui.QHBoxLayout()
        hbox.addWidget(b1)
        hbox.addWidget(b2)
        hbox.addWidget(b3)

        hbox.setStretchFactor(b1, 1)
        hbox.setStretchFactor(b2, 5)
        hbox.setStretchFactor(b3, 8)

        self.setLayout(hbox)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())