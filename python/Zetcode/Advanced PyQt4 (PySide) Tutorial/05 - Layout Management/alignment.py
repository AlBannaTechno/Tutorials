#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 250, 130)
        self.setWindowTitle("Alignment")
        self.initUI()

    def initUI(self):
        btn1 = QtGui.QPushButton("Left", self)
        btn2 = QtGui.QPushButton("Center", self)
        btn3 = QtGui.QPushButton("Right", self)
        btn4 = QtGui.QPushButton("Stretch", self)

        vbox = QtGui.QVBoxLayout()

        hbox1 = QtGui.QHBoxLayout()
        hbox2 = QtGui.QHBoxLayout()
        hbox3 = QtGui.QHBoxLayout()

        hbox1.addWidget(btn1)
        hbox1.setAlignment(QtCore.Qt.AlignLeft)
        hbox2.addWidget(btn2)
        hbox2.setAlignment(QtCore.Qt.AlignCenter)
        hbox3.addWidget(btn3)
        hbox3.setAlignment(QtCore.Qt.AlignRight)

        vbox.addLayout(hbox1)
        vbox.addLayout(hbox2)
        vbox.addLayout(hbox3)
        vbox.addWidget(btn4)
        self.setLayout(vbox)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())