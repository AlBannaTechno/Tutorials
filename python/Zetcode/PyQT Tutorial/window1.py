from PyQt4.QtCore import Qt, SIGNAL
from PyQt4.QtGui import *

from ui_window import Ui_Window
import pypi

class Window(QWidget, Ui_Window):

	terms = ["name", "version", "author", "author_email", "maintainer", "maintainer_email", 
			 "home_page", "license", "summary", "description", "keywords", "platform",
			 "download_url"]

	def __init__(self, parent = None):

		QWidget.__init__(self, parent)
		self.setupUi(self)
		self.connect(self.searchButton, SIGNAL("clicked()"), self.search)

	def search(self):

		self.treeWidget.clear()

		qApp.setOverrideCursor(Qt.WaitCursor)

		server = pypi.PackageServer("http://pypi.python.org/pypi")
		matches = server.search(
			{ unicode(self.terms[self.fieldCombo.currentIndex()]):
			  unicode(self.termsEdit.text()) }, "and" )

		qApp.restoreOverrideCursor()

		if len(matches) == 0:
			QMessageBox.information(self, self.tr("PyPI Information"), self.tr("No Results Found"))
			return
		
		for match in matches:
			item = QTreeWidgetItem()
			
			if not match["name"]:
				continue
			
			item.setText(0, match["name"])

			if match["summary"]:
				item.setText(1, match["summary"])
			
			self.treeWidget.addTopLevelItem(item)