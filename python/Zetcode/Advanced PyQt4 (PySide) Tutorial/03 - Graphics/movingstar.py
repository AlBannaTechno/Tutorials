#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)
        self.initExample()

        self.setGeometry(300, 300, 350, 250)
        self.setWindowTitle("Moving Star")

    def initExample(self):
        self.points = [
            [0, 85], [75, 75], [100, 10], [125, 75],
            [200, 85], [150, 125], [160, 190], [100, 150],
            [40, 190], [50, 125], [0, 85]
        ]

        self.angle = 0
        self.scale = 1
        self.delta = 0.01
        self.timerId = self.startTimer(15)

    def paintEvent(self, event):
        painter = QtGui.QPainter()
        painter.begin(self)
        self.drawStar(painter)
        painter.end()

    def drawStar(self, painter):
        painter.setRenderHint(QtGui.QPainter.Antialiasing)

        h = self.height()
        w = self.width()

        painter.translate(w/2, h/2)
        painter.rotate(self.angle)
        painter.scale(self.scale, self.scale)

        path = QtGui.QPainterPath()
        path.moveTo(self.points[0][0], self.points[0][1])

        for i in range(len(self.points)):
            path.lineTo(self.points[i][0], self.points[i][1])

        brush = QtGui.QBrush(QtCore.Qt.SolidPattern)
        painter.fillPath(path, brush)

    def timerEvent(self, event):
        if self.scale < 0.01:
            self.delta = -self.delta

        elif self.scale > 0.99:
            self.delta = -self.delta

        self.scale += self.delta
        self.angle += 1

        self.repaint()


app = QtGui.QApplication([])
root = Example()
root.show()
sys.exit(app.exec_())