#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

trs = (
    ( 0.0, 0.15, 0.30, 0.5, 0.65, 0.80, 0.9, 1.0 ),
    ( 1.0, 0.0, 0.15, 0.30, 0.5, 0.65, 0.8, 0.9 ),
    ( 0.9, 1.0, 0.0, 0.15, 0.3, 0.5, 0.65, 0.8 ),
    ( 0.8, 0.9, 1.0, 0.0, 0.15, 0.3, 0.5, 0.65 ),
    ( 0.65, 0.8, 0.9, 1.0, 0.0, 0.15, 0.3, 0.5 ),
    ( 0.5, 0.65, 0.8, 0.9, 1.0, 0.0, 0.15, 0.3 ),
    ( 0.3, 0.5, 0.65, 0.8, 0.9, 1.0, 0.0, 0.15 ),
    ( 0.15, 0.3, 0.5, 0.65, 0.8, 0.9, 1.0, 0.0 ),
)

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.initExample()

        self.setGeometry(300, 300, 250, 200)
        self.setWindowTitle("Waiting")

    def initExample(self):
        self.count = 0
        self.timerId = self.startTimer(105)

    def paintEvent(self, event):
        painter = QtGui.QPainter()
        painter.begin(self)
        self.drawLines(painter)
        painter.end()

    def drawLines(self, painter):
        pen = QtGui.QPen()
        pen.setWidth(3)
        pen.setCapStyle(QtCore.Qt.RoundCap)

        width = self.width()
        height = self.height()

        painter.translate(width/2, height/2)
        painter.setPen(pen)

        for i in range(8):
            painter.setOpacity(trs[self.count%8][i])
            painter.drawLine(0.0, -10.0, 0.0, -40.0)
            painter.rotate(45)

    def timerEvent(self, event):
        self.count += 1
        self.repaint()


app = QtGui.QApplication(sys.argv)
root = Example()
root.show()
sys.exit(app.exec_())