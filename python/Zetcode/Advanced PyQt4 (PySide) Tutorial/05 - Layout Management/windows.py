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
        hlpBtn.setSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        okBtn = QtGui.QPushButton("OK")

        listView = QtGui.QListView()

        vbox = QtGui.QVBoxLayout()
        hbox1 = QtGui.QHBoxLayout()
        hbox1.addWidget(windows)
        vbox.addLayout(hbox1)

        hbox2 = QtGui.QHBoxLayout()
        vbox1 = QtGui.QVBoxLayout()
        vboxr = QtGui.QVBoxLayout()

        vbox1.addWidget(listView)
        vboxr.addWidget(actBtn)
        vboxr.addWidget(clsBtn)

        vboxr.setAlignment(clsBtn, QtCore.Qt.AlignTop)

        hbox2.addLayout(vbox1)
        hbox2.addLayout(vboxr)
        vbox.addLayout(hbox2)

        hbox3 = QtGui.QHBoxLayout()
        hbox3.addWidget(hlpBtn)
        hbox3.addWidget(okBtn)
        hbox3.setAlignment(okBtn, QtCore.Qt.AlignRight)
        vbox.addLayout(hbox3)

        self.setLayout(vbox)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())