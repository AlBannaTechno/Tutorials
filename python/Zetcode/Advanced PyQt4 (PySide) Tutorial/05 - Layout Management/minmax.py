#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.move(300, 300)
        self.setWindowTitle("MixMax")
        self.initUI()

    def initUI(self):
        te = QtGui.QTextEdit()
        te.setMinimumSize(15, 15)
        te.setMaximumSize(350, 350)

        layout = QtGui.QHBoxLayout()
        layout.addWidget(te)
        self.setLayout(layout)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())