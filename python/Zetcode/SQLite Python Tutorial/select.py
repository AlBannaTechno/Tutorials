#!/usr/bin/env python
#-*- encoding: utf-8 -*-


import sqlite3
import sys


with sqlite3.connect('test.db') as con:
    cur = con.cursor()
    cur.execute('SELECT * FROM Cars')

    rows = cur.fetchall()
    for row in rows:
        print row
