#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 350, 280)
        self.setWindowTitle("Puff")

        self.initExample()

    def initExample(self):
        self.h = 1
        self.opacity = 1.0
        self.timerId = self.startTimer(15)

    def paintEvent(self, event):
        painter = QtGui.QPainter()
        painter.begin(self)
        self.doStep(painter)
        painter.end()

    def doStep(self, painter):
        text = "ZetCode"

        brush = QtGui.QBrush(QtGui.QColor("#575555"))
        painter.setPen(QtGui.QPen(brush, 1))

        f = QtGui.QFont("Courier", self.h)
        f.setWeight(QtGui.QFont.DemiBold)
        fm = QtGui.QFontMetrics(f)
        textWidth = fm.width(text)

        painter.setFont(f)

        if self.h > 10:
            self.opacity -= 0.01
            painter.setOpacity(self.opacity)

        if self.opacity <= 0:
            self.killTimer(self.timerId)

        h = self.height()
        w = self.width()

        painter.translate(QtCore.QPoint(w/2, h/2))
        painter.drawText(-textWidth/2, 0, text)

    def timerEvent(self, event):
        self.h += 1
        self.repaint()


app = QtGui.QApplication(sys.argv)
root = Example()
root.show()
sys.exit(app.exec_())