#!/usr/bin/env python
# -*- encoding: utf-8 -*-


from PySide import QtCore, QtGui


data = (
    ['Jessica Alba', 'Pomona', '1981'],
    ['Angelina Jolie', 'New York', '1975'],
    ['Natalie Portman', 'Yerusalem', '1981'],
    ['Scarlett Jonahsson', 'New York', '1984'] )


class Example(QtGui.QWidget):
    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 350, 250)
        self.setWindowTitle('Actresses')

        self.initData()
        self.initUI()

    def initData(self):
        self.model = QtGui.QStandardItemModel()
        self.model.setHorizontalHeaderLabels(['Name', 'Place', 'Born'])

        for i in range(len(data)):
            name = QtGui.QStandardItem(data[i][0])
            place = QtGui.QStandardItem(data[i][1])
            born = QtGui.QStandardItem(data[i][2])
            self.model.appendRow((name, place, born))

    def initUI(self):
        ui_name_treev = QtGui.QTreeView(self)
        ui_name_treev.setRootIsDecorated(False)
        ui_name_treev.setModel(self.model)
        ui_name_treev.setSelectionBehavior(QtGui.QAbstractItemView.SelectRows)

        self.ui_info_lbl = QtGui.QLabel(self)

        layout = QtGui.QVBoxLayout()
        layout.addWidget(ui_name_treev)
        layout.addWidget(self.ui_info_lbl)
        self.setLayout(layout)

        ui_name_treev.clicked.connect(self.onClicked)

    def onClicked(self, idx):
        row = idx.row()
        cols = self.model.columnCount()
        text = ''

        for col in range(cols):
            text += self.model.item(row, col).text()
            if col != cols - 1:
                text += ', '

        self.ui_info_lbl.setText(text)


if __name__ == '__main__':
    import sys

    app = QtGui.QApplication([])
    root = Example()
    root.show()

    sys.exit(app.exec_())
