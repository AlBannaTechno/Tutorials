#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 590, 90)
        self.setWindowTitle("Transparent Rectangle")

    def paintEvent(self, event):
        painter = QtGui.QPainter()
        painter.begin(self)
        self.drawRectangles(painter)
        painter.end()

    def drawRectangles(self, painter):
        for i in range(1, 11):
            painter.setOpacity(i*0.1)
            painter.fillRect(50*i, 20, 40, 40, QtCore.Qt.darkGray)


app = QtGui.QApplication(sys.argv)
root = Example()
root.show()
sys.exit(app.exec_())