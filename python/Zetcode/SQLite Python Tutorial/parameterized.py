#!/usr/bin/env python
#-*- encoding: utf-8 -*-


import sqlite3
import sys


uId = 1
uPrice = 62300

with sqlite3.connect('test.db') as con:
    cur = con.cursor()
    cur.execute('UPDATE Cars SET Price=? WHERE Id=?', (uPrice, uId))
    con.commit()

    print 'Number of rows updated: {}'.format(cur.rowcount)
