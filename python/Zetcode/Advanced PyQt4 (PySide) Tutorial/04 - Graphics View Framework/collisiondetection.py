#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Item(QtGui.QGraphicsItem):

    def __init__(self):
        QtGui.QGraphicsItem.__init__(self)
        self.brush = None
        self.createPolygon()

    def createPolygon(self):
        self.polygon = QtGui.QPolygonF()

        self.polygon.append(QtCore.QPointF(130, 140))
        self.polygon.append(QtCore.QPointF(180, 170))
        self.polygon.append(QtCore.QPointF(180, 140))
        self.polygon.append(QtCore.QPointF(220, 110))
        self.polygon.append(QtCore.QPointF(140, 100))

    def shape(self):
        path = QtGui.QPainterPath()
        path.addPolygon(self.polygon)
        return path

    def paint(self, painter, option, widget):
        if self.brush:
            painter.setBrush(self.brush)

        painter.drawPolygon(self.polygon)

    def setBrush(self, brush):
        self.brush = brush

    def boundingRect(self):
        return self.polygon.boundingRect()


class MyView(QtGui.QGraphicsView):

    def __init__(self):
        QtGui.QGraphicsView.__init__(self)

        self.initView()
        self.initScene()
        self.checkCollisions()

    def initView(self):
        self.setWindowTitle("Collision Detection")
        self.setRenderHint(QtGui.QPainter.Antialiasing)
        self.setGeometry(300, 300, 300, 250)

    def initScene(self):
        self.scene = QtGui.QGraphicsScene(self)
        self.scene.setSceneRect(0, 0, 300, 250)

        self.item = Item()
        self.scene.addItem(self.item)

        self.scene.addEllipse(160, 60, 40, 40)
        self.scene.addEllipse(80, 80, 80, 80)
        self.scene.addEllipse(190, 120, 60, 60)
        self.scene.addEllipse(150, 165, 50, 50)

        self.setScene(self.scene)

    def checkCollisions(self):
        items = self.scene.items()

        brush = QtGui.QBrush(QtCore.Qt.SolidPattern)
        brush.setStyle(QtCore.Qt.HorPattern)

        for i in range(len(items)):
            item = items[i]

            if self.scene.collidingItems(item):
                item.setBrush(brush)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = MyView()
    root.show()
    sys.exit(app.exec_())