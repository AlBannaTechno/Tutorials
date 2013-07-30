#!/usr/bin/env python
# -*- encoding: utf-8 -*-


from PySide import QtCore, QtGui


class Example(QtGui.QWidget):
    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 250, 200)
        self.setWindowTitle('QListView')

        self.initData()
        self.initUI()

    def initData(self):
        names = ['Jack', 'Tom', 'Lucy', 'Bill', 'Jane']
        self.ui_model = QtGui.QStringListModel(names)

    def initUI(self):
        ui_names_listv = QtGui.QListView()
        ui_names_listv.setModel(self.ui_model)

        layout = QtGui.QVBoxLayout()
        layout.addWidget(ui_names_listv)
        self.setLayout(layout)


if __name__ == '__main__':
    import sys

    app = QtGui.QApplication([])
    root = Example()
    root.show()

    sys.exit(app.exec_())