#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Item(QtGui.QGraphicsRectItem):

    def __init__(self, x, y, w, h):
        QtGui.QGraphicsRectItem.__init__(self, x, y, w, h)

        self.setFlag(QtGui.QGraphicsItem.ItemIsMovable, True)
        self.setCursor(QtCore.Qt.SizeAllCursor)
        self.setBrush(QtGui.QColor(250, 100, 0))
        self.setPen(QtGui.QPen(QtCore.Qt.NoPen))


class Example(QtGui.QGraphicsView):

    def __init__(self):
        QtGui.QGraphicsView.__init__(self)

        self.setGeometry(300, 300, 300, 300)
        self.setWindowTitle("Custom Item")
        self.init()

    def init(self):
        self.scene = QtGui.QGraphicsScene()

        self.item = Item(0, 0, 100, 100)
        self.scene.addItem(self.item)

        self.setScene(self.scene)


app = QtGui.QApplication([])
root = Example()
root.show()
sys.exit(app.exec_())