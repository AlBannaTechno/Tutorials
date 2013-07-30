#!/usr/bin/env python

import time
import sys
from PySide import QtGui, QtCore

class MyThread(QtCore.QThread):

    def __init__(self):
        QtCore.QThread.__init__(self)
        self.c = Communicate()
        self.alpha = 1

    def run(self):
        while self.alpha >= 0:
            self.alpha -= 0.01
            self.c.fading.emit(self.alpha)
            time.sleep(0.1)


class Communicate(QtCore.QObject):
    fading = QtCore.Signal(float)


class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.initExample()

        self.setGeometry(300, 300, 250, 150)
        self.setWindowTitle("Hit Test")

    def initExample(self):
        self.rect = QtCore.QRect(20, 20, 80, 80)
        self.alpha = 1

        self.mthread = MyThread()
        self.mthread.c.fading.connect(self.fade, QtCore.Qt.QueuedConnection)

    def paintEvent(self, event):
        painter = QtGui.QPainter()
        painter.begin(self)
        self.drawRectangle(painter)
        painter.end()

    def fade(self, alpha):
        self.alpha = alpha
        self.repaint()

    def mousePressEvent(self, event):
        if (event.button() == QtCore.Qt.LeftButton) and (self.alpha == 1):
            x = event.x()
            y = event.y()

            if self.rect.contains(x, y):
                if not self.mthread.isRunning():
                    self.mthread.start()

    def drawRectangle(self, painter):
        painter.setOpacity(self.alpha)
        painter.setBrush(QtGui.QBrush(QtCore.Qt.black))
        painter.setPen(QtCore.Qt.NoPen)
        painter.drawRect(self.rect)


app = QtGui.QApplication(sys.argv)
root = Example()
root.show()
sys.exit(app.exec_())