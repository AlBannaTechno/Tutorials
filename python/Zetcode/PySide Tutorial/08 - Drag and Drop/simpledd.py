#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# simpledd.py

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
        qe = QtGui.QLineEdit('', self)
        qe.setDragEnabled(True)
        qe.move(30, 65)

        button = Button("Button", self)
        button.move(190, 65)

        self.setGeometry(300, 300, 300, 150)
        self.setWindowTitle("Simple Drag & Drop")
        self.show()


####################################################################################################
class Button(QtGui.QPushButton):

    def __init__(self, title, parent):
        QtGui.QPushButton.__init__(self, title, parent)
        self.setAcceptDrops(True)

    def dragEnterEvent(self, e):
        if e.mimeData().hasFormat("text/plain"):
            e.accept()
        else:
            e.ignore()

    def dropEvent(self, e):
        self.setText(e.mimeData().text())


####################################################################################################
if __name__ == "__main__":
    main()