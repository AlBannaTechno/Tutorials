#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# drawpoints.py

import sys
import random
from PySide import QtGui, QtCore

####################################################################################################
def main():
    app = QtGui.QApplication(sys.argv)
    root = Example()
    sys.exit(app.exec_())

####################################################################################################
class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)
        self.initUI()

    def initUI(self):
        self.setGeometry(300, 300, 280, 170)
        self.setWindowTitle("Points")
        self.show()

    def paintEvent(self, e):
        qp = QtGui.QPainter()
        qp.begin(self)
        self.drawPoints(qp)
        qp.end()

    def drawPoints(self, qp):
        qp.setPen(QtCore.Qt.red)
        size = self.size()

        for i in xrange(1000):
            x = random.randint(1, size.width() - 1)
            y = random.randint(1, size.height() - 1)
            qp.drawPoint(x, y)

####################################################################################################
if __name__ == "__main__":
    main()