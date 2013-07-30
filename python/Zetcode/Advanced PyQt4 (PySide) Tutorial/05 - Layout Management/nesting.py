#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.move(300, 300)
        self.setWindowTitle("Nesting")
        self.initUI()

    def initUI(self):
        hbox = QtGui.QHBoxLayout()
        hbox.addStretch(1)
        hbox.addWidget(QtGui.QPushButton("Button"))

        vbox1 = QtGui.QVBoxLayout()
        vbox1.addStretch(1)
        vbox1.addWidget(QtGui.QPushButton("Button"))
        vbox1.addWidget(QtGui.QPushButton("Button"))
        vbox1.addStretch(1)

        vbox2 = QtGui.QVBoxLayout()
        vbox2.addStretch(1)
        vbox2.addWidget(QtGui.QPushButton("Button"))
        vbox2.addWidget(QtGui.QPushButton("Button"))
        vbox2.addWidget(QtGui.QPushButton("Button"))
        vbox2.addStretch(1)

        vbox3 = QtGui.QVBoxLayout()
        vbox3.addStretch(1)
        vbox3.addWidget(QtGui.QPushButton("Button"))
        vbox3.addWidget(QtGui.QPushButton("Button"))
        vbox3.addWidget(QtGui.QPushButton("Button"))
        vbox3.addWidget(QtGui.QPushButton("Button"))
        vbox3.addStretch(1)

        hbox.addLayout(vbox1)
        hbox.addLayout(vbox2)
        hbox.addLayout(vbox3)
        hbox.addStretch(1)

        self.setLayout(hbox)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())