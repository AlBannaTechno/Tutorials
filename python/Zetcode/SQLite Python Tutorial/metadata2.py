#!/usr/bin/env python
#-*- encoding: utf-8 -*-


import sqlite3
import sys


with sqlite3.connect('test.db') as con:
    cur = con.cursor()
    cur.execute('SELECT * FROM Cars')

    col_names = [cn[0] for cn in cur.description]
    rows = cur.fetchall()

    print '{0} {1:<10} {2}'.format(col_names[0], col_names[1], col_names[2])
    for row in rows:
        print '{0:>2} {1:<10} {2}'.format(row[0], row[1], row[2])
