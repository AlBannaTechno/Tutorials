#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class MyGroup(QtGui.QGraphicsItemGroup):

    def __init__(self):
        QtGui.QGraphicsItemGroup.__init__(self)

        self.setCursor(QtCore.Qt.OpenHandCursor)
        self.setFlag(QtGui.QGraphicsItem.ItemIsMovable, True)
        self.setFlag(QtGui.QGraphicsItem.ItemIsSelectable, True)

    def paint(self, painter, option, widget):
        painter.setRenderHint(QtGui.QPainter.Antialiasing)

        brush = QtGui.QBrush(QtGui.QColor("#333333"))
        pen = QtGui.QPen(brush, 0.5)
        pen.setStyle(QtCore.Qt.DotLine)
        painter.setPen(pen)

        if self.isSelected():
            boundRect = self.boundingRect()
            painter.drawRect(boundRect)


class Scene(QtGui.QGraphicsScene):

    def __init__(self):
        QtGui.QGraphicsScene.__init__(self)
        self.initScene()

    def initScene(self):
        self.r1 = self.addRect(20, 50, 120, 50)
        self.r1.setFlag(QtGui.QGraphicsItem.ItemIsMovable, True)
        self.r1.setFlag(QtGui.QGraphicsItem.ItemIsSelectable, True)

        self.r2 = self.addRect(150, 100, 50, 50)
        self.r2.setFlag(QtGui.QGraphicsItem.ItemIsMovable, True)
        self.r2.setFlag(QtGui.QGraphicsItem.ItemIsSelectable, True)

        self.c = self.addEllipse(30, 150, 60, 60)
        self.c.setFlag(QtGui.QGraphicsItem.ItemIsMovable, True)
        self.c.setFlag(QtGui.QGraphicsItem.ItemIsSelectable, True)


class View(QtGui.QGraphicsView):

    def __init__(self):
        QtGui.QGraphicsView.__init__(self)

        self.setGeometry(300, 300, 300, 300)

        policy = QtCore.Qt.ScrollBarAlwaysOff
        self.setVerticalScrollBarPolicy(policy)
        self.setHorizontalScrollBarPolicy(policy)
        self.setRenderHint(QtGui.QPainter.Antialiasing)
        self.setDragMode(QtGui.QGraphicsView.RubberBandDrag)

        self.init()

    def init(self):
        self.group = None
        self.scene = Scene()
        self.setSceneRect(0, 0, 300, 300)
        self.setScene(self.scene)

    def keyPressEvent(self, event):
        key = event.key()

        if key == QtCore.Qt.Key_U:
            if self.group != None and self.group.isSelected():
                items = self.group.childItems()
                self.scene.destroyItemGroup(self.group)
                self.group = None

                for item in items:
                    item.setSelected(False)

        if key == QtCore.Qt.Key_G:
            if self.group:
                return

            selectedItems = self.scene.selectedItems()

            if len(selectedItems) > 0:
                self.group = MyGroup()

                for item in selectedItems:
                    self.group.addToGroup(item)

                self.scene.addItem(self.group)


class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        hbox = QtGui.QHBoxLayout()

        self.view = View()
        hbox.addWidget(self.view)

        self.setLayout(hbox)
        self.setWindowTitle("Group")
        self.setGeometry(250, 150, 300, 300)


app = QtGui.QApplication([])
root = Example()
root.show()
sys.exit(app.exec_())