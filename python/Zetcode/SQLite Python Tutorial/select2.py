#!/usr/bin/env python
#-*- encoding: utf-8 -*-


import sqlite3
import sys


with sqlite3.connect('test.db') as con:
    cur = con.cursor()
    cur.execute('SELECT * FROM Cars')

    while True:
        row = cur.fetchone()

        if row == None:
            break

        print row[0], row[1], row[2]
