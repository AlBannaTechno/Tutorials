#!/usr/bin/env python
#-*- encoding: utf-8 -*-


import sqlite3
import sys


with sqlite3.connect('test.db') as con:
    cur = con.cursor()
    cur.execute('SELECT sqlite_version()')

    data = cur.fetchone()
    print 'SQLite version: {}'.format(data)
