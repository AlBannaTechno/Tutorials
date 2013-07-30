#!/usr/bin/python
# ../simple0.py
''' A really simple editor program in PyQt4 - stage 0 to 1 - simple.0.py'''

import sys
from PyQt4 import QtGui, QtCore
from ui_simple import Ui_MainWindow

__version__ = "0.0.00"

class MainWindow(QtGui.QMainWindow, Ui_MainWindow):

	def __init__(self, parent=None):

		super(MainWindow, self).__init__(parent)
		self.setupUi(self)


if __name__ == '__main__':

	app = QtGui.QApplication(sys.argv)
	root = MainWindow()
	root.show()
	app.exec_()