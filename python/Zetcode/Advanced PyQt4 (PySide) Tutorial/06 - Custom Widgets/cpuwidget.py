#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class CPU(QtGui.QWidget):

    def __init__(self, parent):
        QtGui.QWidget.__init__(self, parent)

        self.parent = parent
#        self.setMaximumSize(85, 120)

    def paintEvent(self, event):
        painter = QtGui.QPainter()
        painter.begin(self)
        self.drawCustomWidget(painter)
        painter.end()

    def drawCustomWidget(self, painter):
        w = self.width()
        h = self.height()

        painter.scale(w/85.0, h/120.0)
        painter.fillRect(0, 0, w, h, QtCore.Qt.black)

        value = self.parent.getValue()
        pos = value / 5

        for i in range(1, 21):
            if i > pos:
                painter.setBrush(QtGui.QColor("#075100"))
                painter.drawRect(10, 95 - i*4, 30, 5)
                painter.drawRect(41, 95 - i*4, 30, 5)

            else:
                painter.setBrush(QtGui.QColor("#36FF27"))
                painter.drawRect(10, 95 - i*4, 30, 5)
                painter.drawRect(41, 95 - i*4, 30, 5)


class Example(QtGui.QWidget):

    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 200, 240)
        self.setWindowTitle("CPU Widget")
        self.initUI()

    def initUI(self):
        vbox = QtGui.QVBoxLayout()

        self.value = 0

        self.cpu = CPU(self)
        vbox.addWidget(self.cpu)

        self.slider = QtGui.QSlider(QtCore.Qt.Horizontal, self)
        self.slider.setMaximum(100)
        vbox.addWidget(self.slider)

        self.slider.valueChanged.connect(self.changeVal)

        self.setLayout(vbox)

    def changeVal(self):
        self.value = self.slider.value()
        self.cpu.repaint()

    def getValue(self):
        return self.value


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())