#!/usr/bin/env pytho
#-*- encoding: utf-8 -*-


import sqlite3
import sys


uId = 4

with sqlite3.connect('test.db') as con:
    cur = con.cursor()
    cur.execute('SELECT Name, Price FROM Cars WHERE Id=:Id', {"Id": uId})
    con.commit()

    row = cur.fetchone()
    print row[0], row[1]
