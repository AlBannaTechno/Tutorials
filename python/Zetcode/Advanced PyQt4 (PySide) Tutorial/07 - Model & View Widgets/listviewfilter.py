#!/usr/bin/env python
# -*- encoding: utf-8 -*-

from PySide import QtCore, QtGui

FIRST_COLUMN = 0


class Example(QtGui.QWidget):
    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setGeometry(300, 300, 400, 240)
        self.setWindowTitle('Filtering Data')

        self.initData()
        self.initUI()

    def initData(self):
        words = ['radar', 'Robert', 'Rome', 'rodeo', 'rust', 'ready', 'robot', 'rampart', 'RAM',
                 'ROM']
        self.model = QtGui.QStringListModel(words)
        self.filtered_model = QtGui.QSortFilterProxyModel(self)
        self.filtered_model.setSourceModel(self.model)
        self.filtered_model.setDynamicSortFilter(True)

    def initUI(self):
        self.ui_filter_text_edit = QtGui.QLineEdit(self)
        self.ui_filter_text_edit.move(250, 20)

        self.ui_case_cbx = QtGui.QCheckBox('Case Sensitive', self)
        self.ui_case_cbx.move(250, 70)

        self.ui_filter_combo = QtGui.QComboBox(self)
        self.ui_filter_combo.addItem('Regular Expression', QtCore.QRegExp.RegExp)
        self.ui_filter_combo.addItem('Wildcard', QtCore.QRegExp.Wildcard)
        self.ui_filter_combo.addItem('Fixed String', QtCore.QRegExp.FixedString)
        self.ui_filter_combo.move(20, 190)

        self.ui_filter_combo.activated.connect(self.filterItems)
        self.ui_filter_text_edit.textChanged.connect(self.filterItems)
        self.ui_case_cbx.toggled.connect(self.filterItems)

        self.ui_info_listv = QtGui.QListView(self)
        self.ui_info_listv.setModel(self.filtered_model)
        self.ui_info_listv.setGeometry(20, 20, 200, 150)

    def filterItems(self, value):
        index = self.ui_filter_combo.currentIndex()
        syntax_type = self.ui_filter_combo.itemData(index)
        syntax = QtCore.QRegExp.PatternSyntax(syntax_type)

        if self.ui_case_cbx.isChecked():
            case = QtCore.Qt.CaseSensitive
        else:
            case = QtCore.Qt.CaseInsensitive

        regExp = QtCore.QRegExp(self.ui_filter_text_edit.text(), case, syntax)
        self.filtered_model.setFilterRegExp(regExp)


if __name__ == '__main__':
    import sys

    app = QtGui.QApplication([])
    root = Example()
    root.show()

    sys.exit(app.exec_())