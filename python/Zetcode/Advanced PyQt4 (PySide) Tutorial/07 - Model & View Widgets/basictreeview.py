#!/usr/bin/env python
# -*- encoding: utf-8 -*-


from PySide import QtCore, QtGui


class Example(QtGui.QWidget):
    def __init__(self, parent=None):
        QtGui.QWidget.__init__(self, parent)

        self.setGeometry(300, 300, 400, 350)
        self.setWindowTitle('QFileSystemModel')

        self.initUI()

    def initUI(self):
        self.ui_model = QtGui.QFileSystemModel()
        self.ui_model.setRootPath(QtCore.QDir.homePath())

        ui_home_treev = QtGui.QTreeView()
        ui_home_treev.setModel(self.ui_model)

        layout = QtGui.QVBoxLayout()
        layout.addWidget(ui_home_treev)
        self.setLayout(layout)


if __name__ == '__main__':
    import sys

    app = QtGui.QApplication([])
    root = Example()
    root.show()

    sys.exit(app.exec_())