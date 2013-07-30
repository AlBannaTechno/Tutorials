#!/usr/bin/python
# -*- coding: utf-8 -*-

# messagebox.py

import sys
from PyQt4 import QtGui

class MessageBox(QtGui.QWidget):

	def __init__(self, parent=None):

		QtGui.QWidget.__init__(self, parent)

		self.setGeometry(300, 300, 250, 150)
		self.setWindowTitle('message box')

	def closeEvent(self, event):

		# object, titlebar, message, buttons, default selection
		# reply = QtGui.QMessageBox.question(self, 'Message', "Are you sure you want to quit?",
		# 	QtGui.QMessageBox.Yes | QtGui.QMessageBox.No, QtGui.QMessageBox.No)
		QtGui.QMessageBox.warning(self, 'IP Address Entry Error',
						'Invalid IP Address format was given. Please enter an' +
						'\nIP address in format n.n.n.n where n is 0 <= n <= 255.')

		if reply == QtGui.QMessageBox.Yes:
			event.accept()
		else:
			event.ignore()


app = QtGui.QApplication(sys.argv)
qb = MessageBox()
qb.show()
sys.exit(app.exec_())