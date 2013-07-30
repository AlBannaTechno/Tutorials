#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore, QtSvg

RED = 0
GREEN = 1
ORANGE = 2
BLACK = 3

class Led(QtGui.QWidget):

    def __init__(self, parent):
        QtGui.QWidget.__init__(self, parent)

        self.color = GREEN
        self.setMinimumSize(QtCore.QSize(50, 50))
        self.setMaximumSize(QtCore.QSize(50, 50))

        self.colors = ["./red.svg", "./green.svg", "./orange.svg", "./black.svg"]

    def paintEvent(self, event):
        painter = QtGui.QPainter()
        painter.begin(self)
        self.drawCustomWidget(painter)
        painter.end()

    def drawCustomWidget(self, painter):
        renderer = QtSvg.QSvgRenderer()
        renderer.load(self.colors[self.color])
        renderer.render(painter)

    def setColor(self, newColor):
        self.color = newColor
        self.update()


class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle("LED Widget")
        self.initUI()

    def initUI(self):
        vbox = QtGui.QVBoxLayout()
        hbox = QtGui.QHBoxLayout()

        self.led = Led(self)

        hbox.addWidget(self.led)
        vbox.addStretch(1)
        vbox.addLayout(hbox)
        vbox.addStretch(1)

        hbox = QtGui.QHBoxLayout()

        self.pb1 = QtGui.QPushButton("Normal", self)
        self.pb2 = QtGui.QPushButton("Warning", self)
        self.pb3 = QtGui.QPushButton("Emergency", self)
        self.pb4 = QtGui.QPushButton("Off", self)

        hbox.addWidget(self.pb1)
        hbox.addWidget(self.pb2)
        hbox.addWidget(self.pb3)
        hbox.addWidget(self.pb4)

        vbox.addLayout(hbox)

        self.pb1.clicked.connect(self.onClick)
        self.pb2.clicked.connect(self.onClick)
        self.pb3.clicked.connect(self.onClick)
        self.pb4.clicked.connect(self.onClick)

        self.setLayout(vbox)

    def onClick(self):
        sender = self.sender()
        text = sender.text()

        if text == "Normal":
            self.led.setColor(GREEN)

        elif text == "Warning":
            self.led.setColor(ORANGE)

        elif text == "Emergency":
            self.led.setColor(RED)

        elif text == "Off":
            self.led.setColor(BLACK)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())