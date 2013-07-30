#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 350, 300)
        self.setWindowTitle("Windows")
        self.initUI()

    def initUI(self):
        windows = QtGui.QLabel("Windows")

        actBtn = QtGui.QPushButton("Activate")
        clsBtn = QtGui.QPushButton("Close")
        hlpBtn = QtGui.QPushButton("Help")
        okBtn = QtGui.QPushButton("OK")

        listView = QtGui.QListView()

        grid = QtGui.QGridLayout()
        grid.addWidget(windows, 0, 0)
        grid.addWidget(listView, 1, 0, 2, 2)
        grid.addWidget(actBtn, 1, 4)
        grid.addWidget(clsBtn, 2, 4)
        grid.addWidget(hlpBtn, 4, 0)
        grid.addWidget(okBtn, 4, 4)
        grid.setColumnStretch(1, 1)
        grid.setRowStretch(2, 1)
        grid.setAlignment(clsBtn, QtCore.Qt.AlignTop)

        self.setLayout(grid)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())