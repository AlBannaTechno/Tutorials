#!/usr/bin/env python
# -*- encoding: utf-8 -*-

from PySide import QtCore, QtGui


class MyListModel(QtCore.QAbstractListModel):
    dataChanged = QtCore.Signal(QtCore.QModelIndex, QtCore.QModelIndex)

    def __init__(self, lang):
        QtCore.QAbstractListModel.__init__(self)
        self.lang = lang

    def data(self, index, role):
        if index.isValid() and role == QtCore.Qt.DisplayRole:
            return self.lang[index.row()]
        else:
            return None

    def setData(self, index, value, role):
        if not value or not index.isValid():
            return False

        if role == QtCore.Qt.EditRole:
            self.lang[index.row()] = value
            self.dataChanged.emit(index, index)
            return True
        else:
            return False

    def rowCount(self, index=QtCore.QModelIndex()):
        return len(self.lang)

    def flags(self, index):
        flag1 = QtCore.Qt.ItemIsEnabled
        flag2 = QtCore.Qt.ItemIsSelectable
        flag3 = QtCore.Qt.ItemIsEditable
        return flag1 | flag2 | flag3


class Example(QtGui.QWidget):
    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 250, 200)
        self.setWindowTitle('Subclass 2')

        self.initUI()

    def initUI(self):
        languages = ['Python', 'Ruby', 'Java', 'C', 'C#', 'C++']

        self.model = MyListModel(languages)

        ui_languages_listv = QtGui.QListView(self)
        ui_languages_listv.setModel(self.model)

        layout = QtGui.QVBoxLayout()
        layout.addWidget(ui_languages_listv)
        self.setLayout(layout)


if __name__ == '__main__':
    import sys

    app = QtGui.QApplication([])
    root = Example()
    root.show()

    sys.exit(app.exec_())