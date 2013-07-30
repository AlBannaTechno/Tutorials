#!/usr/bin/env python
# -*- encoding: utf-8 -*-


from PySide import QtCore, QtGui


class Example(QtGui.QWidget):
    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 350, 250)
        self.setWindowTitle('QTableView')

        self.initData()
        self.initUI()

    def initData(self):
        data = (2, 3, 6, 7, 3, 9, 12, 23)
        self.ui_model = QtGui.QStandardItemModel(10, 6)

        row = 0
        col = 0

        for i in data:
            item = QtGui.QStandardItem(str(i))
            self.ui_model.setItem(row, col, item)
            row += 1

    def initUI(self):
        self.ui_data_tablev = QtGui.QTableView()
        self.ui_data_tablev.setModel(self.ui_model)

        layout = QtGui.QVBoxLayout()
        layout.addWidget(self.ui_data_tablev)
        self.setLayout(layout)


if __name__ == '__main__':
    import sys

    app = QtGui.QApplication([])
    root = Example()
    root.show()

    sys.exit(app.exec_())