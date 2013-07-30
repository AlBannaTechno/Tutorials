#!/usr/bin/env python
# -*- encoding: utf-8 -*-

from PySide import QtCore, QtGui


class MyListModel(QtCore.QAbstractListModel):
    def __init__(self, lang):
        QtCore.QAbstractListModel.__init__(self)

        self.lang = lang

    def data(self, index, role):
        if index.isValid() and role == QtCore.Qt.DisplayRole:
            return self.lang[index.row()]
        else:
            return None

    def rowCount(self, index=QtCore.QModelIndex()):
        return len(self.lang)

    def flags(self, index):
        flag1 = QtCore.Qt.ItemIsEnabled
        flag2 = QtCore.Qt.ItemIsSelectable
        return flag1 | flag2


class Example(QtGui.QWidget):
    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 250, 200)
        self.setWindowTitle('Subclassing')

        self.initData()
        self.initUI()

    def initData(self):
        languages = ('Python', 'Ruby', 'Java', 'C', 'C#', 'C++')
        self.model = MyListModel(languages)

    def initUI(self):
        ui_language_listv = QtGui.QListView(self)
        ui_language_listv.setModel(self.model)

        layout = QtGui.QVBoxLayout()
        layout.addWidget(ui_language_listv)
        self.setLayout(layout)


if __name__ == '__main__':
    import sys

    app = QtGui.QApplication([])
    root = Example()
    root.show()

    sys.exit(app.exec_())