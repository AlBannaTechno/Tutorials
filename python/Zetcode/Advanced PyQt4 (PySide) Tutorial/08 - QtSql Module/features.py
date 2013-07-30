#!/usr/bin/env python
# -*- encoding: utf-8 -*-

from PySide import QtCore, QtSql


app = QtCore.QCoreApplication([])
db = QtSql.QSqlDatabase.addDatabase('QSQLITE')

driver = db.driver()
print driver.hasFeature(QtSql.QSqlDriver.Transactions)
print driver.hasFeature(QtSql.QSqlDriver.BLOB)
print driver.hasFeature(QtSql.QSqlDriver.Unicode)
print driver.hasFeature(QtSql.QSqlDriver.MultipleResultSets)
print driver.hasFeature(QtSql.QSqlDriver.QuerySize)