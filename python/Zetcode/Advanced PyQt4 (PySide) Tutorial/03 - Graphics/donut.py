#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 350, 280)
        self.setWindowTitle("Donut")

    def paintEvent(self, event):
        painter = QtGui.QPainter()
        painter.begin(self)
        self.drawDonut(painter)
        painter.end()

    def drawDonut(self, painter):
        brush = QtGui.QBrush(QtGui.QColor("#535353"))
        painter.setPen(QtGui.QPen(brush, 0.5))

        painter.setRenderHint(QtGui.QPainter.Antialiasing)

        height = self.height()
        width = self.width()

        painter.translate(QtCore.QPoint(width/2, height/2))

        rot = 0

        while rot < 360.0:
            painter.drawEllipse(-125, -40, 250, 80)
            painter.rotate(5.0)
            rot += 5.0


app = QtGui.QApplication(sys.argv)
root = Example()
root.show()
sys.exit(app.exec_())