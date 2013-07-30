#!/usr/bin/env python
# -*- encoding: utf-8 -*-

from PySide import QtCore, QtGui


class MyDelegate(QtGui.QStyledItemDelegate):
    def __init__(self):
        QtGui.QStyledItemDelegate.__init__(self)

    def createEditor(self, parent, option, index):
        editor = QtGui.QSpinBox(parent)
        editor.setMinimum(0)
        editor.setMaximum(100)
        return editor

    def setEditorData(self, editor, index):
        model = index.model()
        role = QtCore.Qt.DisplayRole
        editor.setValue(int(model.data(index, role)))

    def setModelData(self, editor, model, index):
        value = editor.value()
        model.setData(index, value)

    def updateEditorGeometry(self, editor, option, index):
        r = option.rect
        r.setHeight(30)
        editor.setGeometry(r)


class Example(QtGui.QWidget):
    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 250, 200)
        self.setWindowTitle('Delegate')

        self.initData()
        self.initUI()

    def initData(self):
        names = ['0', '1', '2', '3', '4']
        self.model = QtGui.QStringListModel(names)

    def initUI(self):
        ui_names_listv = QtGui.QListView(self)
        ui_names_listv.setModel(self.model)

        self.delegate = MyDelegate()
        ui_names_listv.setItemDelegate(self.delegate)

        layout = QtGui.QVBoxLayout()
        layout.addWidget(ui_names_listv)
        self.setLayout(layout)


if __name__ == '__main__':
    import sys

    app = QtGui.QApplication([])
    root = Example()
    root.show()

    sys.exit(app.exec_())