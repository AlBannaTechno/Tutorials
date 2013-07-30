#!/usr/bin/env python
#-*- encoding: utf-8 -*-


import sqlite3
import sys


with sqlite3.connect('test.db') as con:
    con.row_factory = sqlite3.Row

    cur = con.cursor()
    cur.execute('SELECT * FROM Cars')

    rows = cur.fetchall()
    for row in rows:
        print '{} {} {}'.format(row['id'], row['Name'], row['Price'])
