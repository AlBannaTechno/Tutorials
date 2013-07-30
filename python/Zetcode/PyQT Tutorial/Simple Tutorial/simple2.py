#!/usr/bin/python
# ../simple2.py
'''A really simple editor program in PyQt4 - stage 3 - simple2.py'''

import sys
from PyQt4 import QtGui, QtCore
from ui_simple import Ui_MainWindow

__version__ = '0.0.04'

class MainWindow(QtGui.QMainWindow, Ui_MainWindow):

	def __init__(self, parent=None):

		super(MainWindow, self).__init__(parent)

		self.setupUi(self)
		self.actionNew.triggered.connect(self.fileNew)
		self.actionOpen.triggered.connect(self.fileOpen)
		self.actionSave.triggered.connect(self.fileSave)
		self.actionSave_As.triggered.connect(self.fileSaveAs)
		self.fileName = None

	def fileNew(self):

		'''Clear the editor window for a new file with name specified in fileSaveAs method'''
		self.textEdit.setText('')
		self.statusBar().showMessage('File menu: New selected', 8000)

	def fileOpen(self):

		'''Open file'''
		fname = unicode(QtGui.QFileDialog.getOpenFileName(self, 'Open File', '.', 'Files (*.*)'))

		if not (fname == ''):
			self.textEdit.setText(open(fname).read())
			self.fileName = fname
		else:
			return

		self.statusBar().showMessage('File opened ', 8000)

	def fileSave(self):

		if self.fileName is None:
			return self.fileSaveAs()
		else:
			fname = self.fileName
			fl = open(fname, 'w')
			tempText = self.textEdit.toPlainText()
			if tempText:
				fl.write(tempText)
				fl.close()
				self.statusBar().showMessage('Saved file ' + fname, 8000)
			else:
				self.statusBar().showMessage('Failed to save...', 5000)
				return False

	def fileSaveAs(self):

		dir = self.fileName if self.fileName is not None else '.'
		fname = unicode(QtGui.QFileDialog.getSaveFileName(self, 'Simple Editor, SaveAs ', dir, 
						'Any File (*.*)'))
		if fname:
			if '.' not in fname:
				fname += '.txt'
			self.fileName = fname
			self.fileSave()
			self.statusBar().showMessage('SaveAs file ' + fname, 8000)


if __name__ == '__main__':
	app = QtGui.QApplication(sys.argv)
	root = MainWindow()
	root.show()
	app.exec_()