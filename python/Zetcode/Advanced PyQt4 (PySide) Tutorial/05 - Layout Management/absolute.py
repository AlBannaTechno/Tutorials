#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 300, 280)
        self.setWindowTitle("Absolute")
        self.initUI()

    def initUI(self):
        self.setStyleSheet("background-color: #222222")

        bardejov = QtGui.QPixmap("./bardejov.jpg")
        mincol = QtGui.QPixmap("./mincol.jpg")
        rotunda = QtGui.QPixmap("./rotunda.jpg")

        label1 = QtGui.QLabel(self)
        label2 = QtGui.QLabel(self)
        label3 = QtGui.QLabel(self)

        label1.setPixmap(bardejov)
        label2.setPixmap(mincol)
        label3.setPixmap(rotunda)

        label1.setGeometry(20, 20, 120, 90)
        label2.setGeometry(40, 160, 120, 90)
        label3.setGeometry(170, 50, 120, 90)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())