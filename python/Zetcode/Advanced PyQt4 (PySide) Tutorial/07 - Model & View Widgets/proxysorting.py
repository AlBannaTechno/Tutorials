#!/usr/bin/env python
# -*- encoding: utf-8 -*-

from PySide import QtCore, QtGui

FIRST_COLUMN = 0


class Example(QtGui.QWidget):
    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 350, 200)
        self.setWindowTitle('Sorting')

        self.initData()
        self.initUI()

    def initData(self):
        names = ['Jack', 'Tom', 'Lucy', 'Bill', 'Jane']
        self.model = QtGui.QStringListModel(names)
        self.filter_model = QtGui.QSortFilterProxyModel(self)
        self.filter_model.setSourceModel(self.model)

    def initUI(self):
        ui_sort_btn = QtGui.QPushButton('Sort', self)
        ui_sort_btn.move(250, 20)

        self.ui_sort_type_cbx = QtGui.QCheckBox('Ascending', self)
        self.ui_sort_type_cbx.move(250, 60)

        ui_sort_btn.clicked.connect(self.sortItems)

        self.ui_names_listv = QtGui.QListView(self)
        self.ui_names_listv.setModel(self.filter_model)
        self.ui_names_listv.setGeometry(20, 20, 200, 150)

    def sortItems(self):
        if self.ui_sort_type_cbx.isChecked():
            self.filter_model.sort(FIRST_COLUMN, QtCore.Qt.AscendingOrder)
        else:
            self.filter_model.sort(FIRST_COLUMN, QtCore.Qt.DescendingOrder)


if __name__ == '__main__':
    import sys

    app = QtGui.QApplication([])
    root = Example()
    root.show()

    sys.exit(app.exec_())