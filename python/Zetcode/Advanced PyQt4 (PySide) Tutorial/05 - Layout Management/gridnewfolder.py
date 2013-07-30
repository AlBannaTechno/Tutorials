#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 300, 300)
        self.setWindowTitle("New Folder")
        self.initUI()

    def initUI(self):
        grid = QtGui.QGridLayout()
        grid.addWidget(QtGui.QLabel("Name: "), 0, 0)

        line = QtGui.QLineEdit()
        grid.addWidget(line, 0, 1, 1, 3)
        grid.setColumnStretch(1, 1)

        grid.addWidget(QtGui.QListView(), 1, 0, 2, 4)

        ok = QtGui.QPushButton("OK")
        cancel = QtGui.QPushButton("Cancel")

        grid.addWidget(ok, 3, 2)
        grid.addWidget(cancel, 3, 3)

        self.setLayout(grid)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())