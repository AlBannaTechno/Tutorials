#!/usr/bin/env python2.7

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 250, 150)
        self.setWindowTitle("Lines")

        self.cs = [[0 for i in range(2)] for j in range(100)]
        self.count = 0

    def paintEvent(self, event):
        painter = QtGui.QPainter()
        painter.begin(self)
        self.drawLines(painter)
        painter.end()

    def mousePressEvent(self, event):
        if event.button() == QtCore.Qt.LeftButton:
            x = event.x()
            y = event.y()

            self.cs[self.count][0] = x
            self.cs[self.count][1] = y
            self.count = self.count + 1

        if event.button() == QtCore.Qt.RightButton:
            self.repaint()
            self.count = 0

    def drawLines(self, painter):
        painter.setRenderHint(QtGui.QPainter.Antialiasing)

        width = self.width()
        height = self.height()

        painter.eraseRect(0, 0, width, height)

        for i in range(self.count):
            for j in range(self.count):
                painter.drawLine(self.cs[i][0], self.cs[i][1], self.cs[j][0], self.cs[j][1])


app = QtGui.QApplication(sys.argv)
root = Example()
root.show()
sys.exit(app.exec_())