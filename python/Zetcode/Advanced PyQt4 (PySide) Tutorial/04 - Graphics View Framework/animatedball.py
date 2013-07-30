#!/usr/bin/env python

import math
import sys
from PySide import QtGui, QtCore

TIME = 3000

class Image(QtGui.QGraphicsPixmapItem):

    def __init__(self):
        QtGui.QGraphicsPixmapItem.__init__(self)
        self.setPixmap(QtGui.QPixmap("ball.png"))


class MyView(QtGui.QGraphicsView):

    def __init__(self):
        QtGui.QGraphicsView.__init__(self)
        self.initView()

    def initView(self):
        self.setWindowTitle("Sin Ball")
        self.setRenderHint(QtGui.QPainter.Antialiasing)

        self.image = Image()
        self.image.setPos(5, 150)

        self.timer = QtCore.QTimeLine(TIME)
        self.timer.setCurveShape(QtCore.QTimeLine.LinearCurve)
        self.timer.setFrameRange(0, 100)

        self.animation = QtGui.QGraphicsItemAnimation()
        self.animation.setItem(self.image)
        self.animation.setTimeLine(self.timer)

        self.timer.frameChanged.connect(self.doStep)

        for i in range(20):
            self.animation.setPosAt(i/20.0, QtCore.QPointF(i, math.sin(i))*40)

        self.scene = QtGui.QGraphicsScene(self)
        self.scene.setSceneRect(120, -50, 250, 150)
        self.scene.addItem(self.image)

        self.setScene(self.scene)

        self.timer.start()
        self.setGeometry(300, 300, 500, 200)

    def doStep(self, i):
        if self.timer.currentTime() >= TIME/2:
            self.timer.toggleDirection()


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = MyView()
    root.show()
    sys.exit(app.exec_())