#!/usr/bin/python
# ../simple1.py
'''A really simple editor program in PyQt4 - stage 2 - simple1.py'''

import sys
from PyQt4 import QtGui, QtCore
from ui_simple import Ui_MainWindow

__version__ = '0.0.01'

class MainWindow(QtGui.QMainWindow, Ui_MainWindow):

	def __init__(self, parent=None):

		super(MainWindow, self).__init__(parent)
		self.setupUi(self)
		self.connect(self.actionNew, QtCore.SIGNAL('triggered()'), self.fileNew)
		self.actionNew.triggered.connect(self.fileNew)

	def fileNew(self):

		'''Clear the editor window for a new file with name specified in fileSaveAs method'''
		self.textEdit.setText('')
		self.textEdit.append('fileNew pressed')
		self.statusBar().showMessage('File menu: New selected', 8000)


if __name__ == '__main__':

	app = QtGui.QApplication(sys.argv)
	root = MainWindow()
	root.show()
	app.exec_()