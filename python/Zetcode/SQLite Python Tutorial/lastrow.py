#!/usr/bin/env python
#-*- encoding: utf-8 -*-


import sqlite3
import sys


with sqlite3.connect('test.db') as con:
    cur = con.cursor()
    cur.execute('CREATE TABLE Friends(Id INTEGER PRIMARY KEY, Name TEXT);')
    cur.execute("INSERT INTO Friends(Name) VALUES('Tom');")
    cur.execute("INSERT INTO Friends(Name) VALUES('Rebecca');")
    cur.execute("INSERT INTO Friends(Name) VALUES('Jim');")
    cur.execute("INSERT INTO Friends(Name) VALUES('Robert');")

    lid = cur.lastrowid
    print 'The last Id of the inserted row is {}'.format(lid)
