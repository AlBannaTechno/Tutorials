#!/usr/bin/python
# -*- coding: utf-8 -*-

# lineedit.py

from PyQt4 import QtGui
from PyQt4 import QtCore

class Example(QtGui.QWidget):

	def __init__(self, parent=None):

		QtGui.QWidget.__init__(self, parent)

		self.initUI()

	def initUI(self):

		self.label = QtGui.QLabel(self)
		edit = QtGui.QLineEdit(self)

		edit.move(60, 100)
		self.label.move(60, 40)

		self.connect(edit, QtCore.SIGNAL('textChanged(QString)'), self.onChanged)

		self.setWindowTitle('QLineEdit')
		self.setGeometry(250, 200, 350, 250)

	def onChanged(self, text):

		self.label.setText(text)
		self.label.adjustSize()


def main():

	app = QtGui.QApplication([])
	exm = Example()
	exm.show()
	app.exec_()

if __name__ == '__main__':
	main()