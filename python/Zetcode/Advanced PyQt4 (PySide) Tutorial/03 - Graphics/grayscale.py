#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QWidget):
    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.initExample()

        self.setGeometry(200, 200, 320, 150)
        self.setWindowTitle("Sid")

    def initExample(self):
        self.sid = QtGui.QImage("./smallsid.jpg")

        self.w = self.sid.width()
        self.h = self.sid.height()

    def paintEvent(self, event):
        painter = QtGui.QPainter()
        painter.begin(self)
        self.drawImages(painter)
        painter.end()

    def grayScale(self, image):
        for i in range(self.w):
            for j in range(self.h):
                c = image.pixel(i, j)
                gray = QtGui.qGray(c)
                alpha = QtGui.qAlpha(c)
                image.setPixel(i, j, QtGui.qRgba(gray, gray, gray, alpha))

        return image

    def drawImages(self, painter):
        painter.drawImage(5, 15, self.sid)
        painter.drawImage(self.w+10, 15, self.grayScale(self.sid.copy()))


app = QtGui.QApplication(sys.argv)
root = Example()
root.show()
sys.exit(app.exec_())