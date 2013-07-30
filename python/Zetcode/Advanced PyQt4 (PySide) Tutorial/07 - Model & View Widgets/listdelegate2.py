#!/usr/bin/env python
# -*- encoding: utf-8 -*-

from PySide import QtCore, QtGui


class MyDelegate(QtGui.QStyledItemDelegate):
    def __init__(self):
        QtGui.QStyledItemDelegate.__init__(self)

    def paint(self, painter, option, index):
        painter.save()
        painter.setPen(QtGui.QPen(QtCore.Qt.NoPen))

        if option.state & QtGui.QStyle.State_Selected:
            brush = QtGui.QBrush(QtGui.QColor('#66FF71'))
            painter.setBrush(brush)
        else:
            brush = QtGui.QBrush(QtCore.Qt.white)
            painter.setBrush(brush)

        painter.drawRect(option.rect)

        painter.setPen(QtGui.QPen(QtCore.Qt.blue))
        value = index.data(QtCore.Qt.DisplayRole)
        if value:
            text = str(value)
            align = QtCore.Qt.AlignCenter
            painter.drawText(option.rect, align, text)

        painter.restore()


class Example(QtGui.QWidget):
    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 250, 200)
        self.setWindowTitle('Delegate 2')

        self.initData()
        self.initUI()

    def initData(self):
        names = ['Jack', 'Tom', 'Lucy', 'Bill', 'Jane']
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