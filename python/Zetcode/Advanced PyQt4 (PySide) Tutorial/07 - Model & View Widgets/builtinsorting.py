#!/usr/bin/env python
# -*- encoding: utf-8 -*-


from PySide import QtCore, QtGui

FIRST_COLUMN = 0


class Example(QtGui.QWidget):
    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 350, 250)
        self.setWindowTitle('Sorting')

        self.initData()
        self.initUI()

    def initData(self):
        names = ['Jack', 'Tom', 'Lucy', 'Bill', 'Jane']
        self.model = QtGui.QStringListModel(names)

    def initUI(self):
        self.ui_names_tablev = QtGui.QTableView(self)
        self.ui_names_tablev.setModel(self.model)
        self.ui_names_tablev.setSortingEnabled(True)

        ui_sort_btn = QtGui.QPushButton('Sort', self)
        ui_sort_btn.setSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)

        self.ui_sort_type_cbx = QtGui.QCheckBox('Ascending', self)
        self.ui_sort_type_cbx.setSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)

        ui_sort_btn.clicked.connect(self.sortItems)

        hbox_layout = QtGui.QHBoxLayout()
        hbox_layout.addWidget(self.ui_sort_type_cbx)
        hbox_layout.addWidget(ui_sort_btn)

        main_layout = QtGui.QVBoxLayout()
        main_layout.addWidget(self.ui_names_tablev)
        main_layout.addLayout(hbox_layout)
        self.setLayout(main_layout)

    def sortItems(self):
        if self.ui_sort_type_cbx.isChecked():
            self.ui_names_tablev.sortByColumn(FIRST_COLUMN, QtCore.Qt.AscendingOrder)
        else:
            self.ui_names_tablev.sortByColumn(FIRST_COLUMN, QtCore.Qt.DescendingOrder)


if __name__ == '__main__':
    import sys

    app = QtGui.QApplication([])
    root = Example()
    root.show()

    sys.exit(app.exec_())