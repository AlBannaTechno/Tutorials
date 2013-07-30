#!/usr/bin/env python
# -*- encoding: utf-8 -*-

from PySide import QtCore, QtGui


class Example(QtGui.QMainWindow):
    def __init__(self):
        QtGui.QMainWindow.__init__(self)

        self.setGeometry(300, 300, 350, 250)
        self.setWindowTitle('Selection')

        self.initData()
        self.initUI()

    def initData(self):
        self.model = QtGui.QStandardItemModel(15, 15)

    def initUI(self):
        self.ui_selection_tablev = QtGui.QTableView(self)
        self.ui_selection_tablev.setModel(self.model)

        self.ui_sum_act = QtGui.QAction(QtGui.QIcon('./sum.png'), 'Sum', self)
        self.ui_sum_act.triggered.connect(self.onClicked)

        self.ui_main_tbar = self.addToolBar('Sum')
        self.ui_main_tbar.addAction(self.ui_sum_act)

        self.setCentralWidget(self.ui_selection_tablev)

    def onClicked(self):
        nsum = 0

        selected_model = self.ui_selection_tablev.selectionModel()
        selection = selected_model.selection()
        indexes = selection.indexes()

        for idx in indexes:
            nsum += int(idx.data())

        last_index = indexes[-1]
        row, col = last_index.row(), last_index.column()

        item = QtGui.QStandardItem(str(nsum))
        self.model.setItem(row+1, col, item)


if __name__ == '__main__':
    import sys

    app = QtGui.QApplication([])
    root = Example()
    root.show()

    sys.exit(app.exec_())