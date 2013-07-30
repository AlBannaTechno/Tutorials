#!/usr/bin/env python
# -*- encoding: utf-8 -*-


import sqlite3 as lite
import sys


con = None

try:
    con = lite.connect('test.db')

    cur = con.cursor()
    cur.execute('SELECT sqlite_version()')

    data = cur.fetchone()

    print 'SQLite version: {}'.format(data)

except lite.Error as err:
    print 'Error {}:'.format(err.args[0])
    sys.exit(1)

finally:
    if con:
        con.close()
