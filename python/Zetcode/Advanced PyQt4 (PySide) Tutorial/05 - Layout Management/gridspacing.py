#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class MyFrame(QtGui.QFrame):

    def __init__(self):
        QtGui.QFrame.__init__(self)
        self.setFrameStyle(QtGui.QFrame.Panel | QtGui.QFrame.Raised)


class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 350, 200)
        self.setWindowTitle("Spacing")
        self.initUI()

    def initUI(self):
        frame1 = MyFrame()
        frame2 = MyFrame()
        frame3 = MyFrame()
        frame4 = MyFrame()
        frame5 = MyFrame()
        frame6 = MyFrame()

        grid = QtGui.QGridLayout()
        grid.addWidget(frame1, 0, 0)
        grid.addWidget(frame2, 0, 1)
        grid.addWidget(frame3, 0, 2)
        grid.addWidget(frame4, 1, 0)
        grid.addWidget(frame5, 1, 1)
        grid.addWidget(frame6, 1, 2)

        grid.setHorizontalSpacing(3)
        grid.setVerticalSpacing(3)

        self.setLayout(grid)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())