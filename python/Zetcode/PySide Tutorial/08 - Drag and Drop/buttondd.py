#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# buttondd.py

import sys
from PySide import QtGui, QtCore

####################################################################################################
def main():
    app = QtGui.QApplication(sys.argv)
    root = Example()
    sys.exit(app.exec_())

####################################################################################################
class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)
        self.initUI()

    def initUI(self):
        self.setAcceptDrops(True)

        self.btn = Button("Button", self)
        self.btn.move(100, 65)

        self.setGeometry(300, 300, 300, 150)
        self.setWindowTitle("Click or Move")
        self.show()

    def dragEnterEvent(self, e):
        e.accept()

    def dropEvent(self, e):
        position = e.pos()
        self.btn.move(position)

        e.setDropAction(QtCore.Qt.MoveAction)
        e.accept()

####################################################################################################
class Button(QtGui.QPushButton):

    def __init__(self, title, parent):
        QtGui.QPushButton.__init__(self, title, parent)

    def mouseMoveEvent(self, e):
        if e.buttons() != QtCore.Qt.RightButton:
            return

        mimeData = QtCore.QMimeData()

        drag = QtGui.QDrag(self)
        drag.setMimeData(mimeData)
        drag.setHotSpot(e.pos() - self.rect().topLeft())

        dropAction = drag.start(QtCore.Qt.MoveAction)

    def mousePressEvent(self, e):
        QtGui.QPushButton.mousePressEvent(self, e)
        if e.button() == QtCore.Qt.LeftButton:
            print "press"

####################################################################################################
if __name__ == "__main__":
    main()