#!/usr/bin/python
# ../simple3.py - developing of a simple text editor
''' A really simple editor program in PyQt4 - stage 4 - simple3.py'''

import sys
import os
from PyQt4.QtGui import QMainWindow, QApplication, QFileDialog, QKeySequence, QAction, QIcon 
from PyQt4.QtCore import SIGNAL
from ui_simple import Ui_MainWindow
import qrc_simple

__version__ = '0.0.06'

class MainWindow(QMainWindow, Ui_MainWindow):

	def __init__(self, parent=None):

		super(MainWindow, self).__init__(parent)

		self.setupUi(self)
		self.actionNew = self.editAction(self.actionNew, self.fileNew, QKeySequence.New, 'filenew',
				'Clear the textEdit window for a new file.')
		self.actionOpen = self.editAction(self.actionOpen, self.fileOpen, QKeySequence.Open, 
				'fileopen', 'Open an existing file')
		self.actionSave = self.editAction(self.actionSave, self.fileSave, QKeySequence.Save, 
				'filesave', 'Save file')
		self.actionSave_As = self.editAction(self.actionSave_As, self.fileSaveAs, 'Ctrl+A', 
				'filesaveas', 'Save file with a new name')
		self.fileName = None
#---------------------------------------------------------------------------------------------------
		fileToolbar = self.addToolBar('File')
		self.addActions(fileToolbar, (self.actionNew, self.actionOpen, self.actionSave, 
									  self.actionSave_As))
#---------------------------------------------------------------------------------------------------
		self.resize(600, 400)
		self.dirty = False
		self.textEdit.textChanged.connect(self.setDirty)
#---------------------------------------------------------------------------------------------------
	
	def setDirty(self):

		'''On change of text in textEdit window, set the flag 'dirty' to True'''
		if self.dirty:
			return True
		self.dirty = True
		self.updateStatus('self.dirty set to True')

	def clearDirty(self):

		'''Clear the dirty flage and update status'''
		self.dirty = False

	def updateStatus(self, message):

		if self.fileName is not None:
			flbase = os.path.basename(self.fileName)
			self.setWindowTitle(unicode("Simple Editor - " + flbase + "[*]"))
			self.statusBar().showMessage(message, 3000)
		self.setWindowModified(self.dirty)

	def okToContinue(self):

		if self.dirty:
			reply = QMessageBox.question(self, 'Simple Editor - Unsaved Changes', 
					'Save unsaved changes?', QMessageBox.Yes | QMessageBox.No | QMessageBox.Cancel)
			if reply == QMessageBox.Cancel:
				return False
			elif reply == QMessageBox.Yes:
				return self.fileSave()
		return True

	def addActions(self, target, actions):
		for action in actions:
			if action is None:
				target.addSeparator()
			else:
				target.addAction(action)
	
	def editAction(self, action, slot=None, shortcut=None, icon=None, tip=None, checkable=False, 
			signal='triggered()'):

		if icon is not None:
			action.setIcon(QIcon(':/{0}.png'.format(icon)))
		if shortcut is not None:
			action.setShortcut(shortcut)
		if tip is not None:
			action.setToolTip(tip)
			action.setStatusTip(tip)
		if slot is not None:
#			self.connect(action, SIGNAL(signal), slot)
			action.triggered.connect(slot)
		if checkable:
			action.setCheckable(True)
		return action

	def fileNew(self):

		'''Clear the editor window for a new file with name specified in fileSaveAs method.'''
		self.textEdit.setText('')
		self.statusBar().showMessage('File menu: New selected', 8000)

	def fileOpen(self):

		'''Open file'''
		fname = unicode(QFileDialog.getOpenFileName(self, 'Open File', '.', 'Files (*.*)'))
		if not (fname == ''):
			self.textEdit.setText(open(fname).read())
			self.fileName = fname
		else:
			return
		self.clearDirty()
		self.updateStatus('File opened.')

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
				self.clearDirty()
				self.updateStatus('Saved file')
				return True
			else:
				self.statusBar().showMessage('Failed to save ...', 5000)
				return False

	def fileSaveAs(self):

		path = self.fileName if self.fileName is not None else '.'
		fname = unicode(QFileDialog.getSaveFileName(self, 'Simple Editor, SaveAs ', path, 
				'Any File (*.*)'))
		if fname:
			if '.' not in fname:
				fname += '.txt'
			self.fileName = fname
			self.fileSave()
			self.statusBar().showMessage('SaveAs file ' + fname, 8000)
			self.clearDirty()


if __name__ == '__main__':
	app = QApplication(sys.argv)
	root = MainWindow()
	root.show()
	app.exec_()