#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class View(QtGui.QGraphicsView):

    def __init__(self):
        QtGui.QGraphicsView.__init__(self)
        self.setRenderHint(QtGui.QPainter.Antialiasing)


class Scene(QtGui.QGraphicsScene):

    def __init__(self):
        QtGui.QGraphicsScene.__init__(self)
        self.initScene()

    def initScene(self):
        for i in range(5):
            e = self.addEllipse(20*i, 40*i, 50, 50)
            flag1 = QtGui.QGraphicsItem.ItemIsMovable
            flag2 = QtGui.QGraphicsItem.ItemIsSelectable
            e.setFlag(flag1, True)
            e.setFlag(flag2, True)


class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(150, 150, 350, 300)
        self.setWindowTitle("Selection")
        self.initUI()

    def initUI(self):
        hbox = QtGui.QHBoxLayout()

        self.view = View()
        self.scene = Scene()
        self.view.setScene(self.scene)

        hbox.addWidget(self.view)
        frame = QtGui.QFrame()

        self.delete = QtGui.QPushButton("Delete", frame)
        self.delete.setEnabled(False)
        vbox = QtGui.QVBoxLayout()
        vbox.addWidget(self.delete)
        vbox.addStretch(1)

        frame.setLayout(vbox)
        hbox.addWidget(frame)
        self.setLayout(hbox)

        self.delete.clicked.connect(self.onClick)
        self.scene.selectionChanged.connect(self.selectionChanged)

    def onClick(self):
        selectedItems = self.scene.selectedItems()

        if len(selectedItems) > 0:
            for item in selectedItems:
                self.scene.removeItem(item)

    def selectionChanged(self):
        selectedItems = self.scene.selectedItems()

        if len(selectedItems):
            self.delete.setEnabled(True)
        else:
            self.delete.setEnabled(False)


app = QtGui.QApplication([])
root = Example()
root.show()
sys.exit(app.exec_())