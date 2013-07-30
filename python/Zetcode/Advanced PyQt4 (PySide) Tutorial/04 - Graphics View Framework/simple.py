#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QGraphicsView):

    def __init__(self):
        QtGui.QGraphicsView.__init__(self)

        self.setGeometry(300, 300, 250, 150)
        self.setWindowTitle("Simple")
        self.init()

    def init(self):
        self.scene = QtGui.QGraphicsScene()
        self.scene.addText("ZetCode")

        self.setScene(self.scene)


app = QtGui.QApplication([])
root = Example()
root.show()
sys.exit(app.exec_())