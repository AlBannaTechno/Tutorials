#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 450, 200)
        self.setWindowTitle("Stretch Space")
        self.initUI()

    def initUI(self):
        vbox = QtGui.QVBoxLayout()

        hbox1 = QtGui.QHBoxLayout()
        hbox1.addStretch(1)
        hbox1.addWidget(QtGui.QPushButton("Button"))
        hbox1.addWidget(QtGui.QPushButton("Button"))

        hbox2 = QtGui.QHBoxLayout()
        hbox2.addWidget(QtGui.QPushButton("Button"))
        hbox2.addWidget(QtGui.QPushButton("Button"))
        hbox2.addStretch(1)

        hbox3 = QtGui.QHBoxLayout()
        hbox3.addWidget(QtGui.QPushButton("Button"))
        hbox3.addStretch(1)
        hbox3.addWidget(QtGui.QPushButton("Button"))

        hbox4 = QtGui.QHBoxLayout()
        hbox4.addStretch(1)
        hbox4.addWidget(QtGui.QPushButton("Button"))
        hbox4.addWidget(QtGui.QPushButton("Button"))
        hbox4.addStretch(1)

        hbox5 = QtGui.QHBoxLayout()
        hbox5.addWidget(QtGui.QPushButton("Button"))
        hbox5.addStretch(1)
        hbox5.addWidget(QtGui.QPushButton("Button"))
        hbox5.addStretch(1)

        vbox.addLayout(hbox1)
        vbox.addLayout(hbox2)
        vbox.addLayout(hbox3)
        vbox.addLayout(hbox4)
        vbox.addLayout(hbox5)

        self.setLayout(vbox)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())