#!/usr/bin/env python

import sys
from PySide import QtGui, QtCore

class Example(QtGui.QDialog):

    def __init__(self):
        QtGui.QDialog.__init__(self)

        self.move(300, 150)
        self.setWindowTitle("Find/Replace")
        self.initUI()

    def initUI(self):
        vbox = QtGui.QVBoxLayout()

        hbox1 = QtGui.QHBoxLayout()
        hbox1.addWidget(QtGui.QLabel("Find"))
        hbox1.addWidget(QtGui.QComboBox())
        vbox.addLayout(hbox1)

        hbox2 = QtGui.QHBoxLayout()
        hbox2.addWidget(QtGui.QLabel("Replace With"))
        hbox2.addWidget(QtGui.QComboBox())
        vbox.addLayout(hbox2)

        hbox3 = QtGui.QHBoxLayout()

        direction = QtGui.QGroupBox("Direction")
        dirvbox = QtGui.QVBoxLayout()
        dirvbox.addWidget(QtGui.QCheckBox("Forward"))
        dirvbox.addWidget(QtGui.QCheckBox("Backward"))
        direction.setLayout(dirvbox)
        hbox3.addWidget(direction)

        scope = QtGui.QGroupBox("Scope")
        scvbox = QtGui.QVBoxLayout()
        scvbox.addWidget(QtGui.QCheckBox("All"))
        scvbox.addWidget(QtGui.QCheckBox("Selected Items"))
        scope.setLayout(scvbox)
        hbox3.addWidget(scope)

        vbox.addLayout(hbox3)

        options = QtGui.QGroupBox("Options")
        opthbox = QtGui.QHBoxLayout()
        optvbox1 = QtGui.QVBoxLayout()
        optvbox2 = QtGui.QVBoxLayout()

        optvbox1.addWidget(QtGui.QCheckBox("Case Sensitive"))
        optvbox1.addWidget(QtGui.QCheckBox("Whole Word"))
        regex = QtGui.QCheckBox("Regular Expressions")
        optvbox1.addWidget(regex)
        optvbox2.addWidget(QtGui.QCheckBox("Wrap Search"))
        optvbox2.addWidget(QtGui.QCheckBox("Incremental"))

        opthbox.addLayout(optvbox1)
        opthbox.addLayout(optvbox2)
        options.setLayout(opthbox)
        vbox.addWidget(options)

        hbox4 = QtGui.QHBoxLayout()
        hbox4.addWidget(QtGui.QPushButton("Find"))
        hbox4.addWidget(QtGui.QPushButton("Find/Replace"))
        vbox.addLayout(hbox4)

        hbox5 = QtGui.QHBoxLayout()
        hbox5.addWidget(QtGui.QPushButton("Replace"))
        hbox5.addWidget(QtGui.QPushButton("Replace All"))
        vbox.addLayout(hbox5)

        hbox6 = QtGui.QHBoxLayout()
        hbox6.addStretch(1)
        hbox6.addWidget(QtGui.QPushButton("Close"))
        vbox.addLayout(hbox6)

        self.setLayout(vbox)


if __name__ == "__main__":
    app = QtGui.QApplication([])
    root = Example()
    root.show()
    sys.exit(app.exec_())