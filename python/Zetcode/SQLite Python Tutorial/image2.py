#!/usr/bin/env python
#-*- encoding: utf-8 -*-


import sqlite3
import sys


def write_image(data):
    fout = 0

    try:
        fout = open('woman2.jpg', 'wb')
        fout.write(data)

    except IOError as err:
        print 'Error {}: {}'.format(err.args[0], err.args[1])
        sys.exit(1)

    finally:
        if fout:
            fout.close()

con = 0
try:
    con = sqlite3.connect('test.db')
    cur = con.cursor()
    cur.execute('SELECT Data FROM Images LIMIT 1')
    data = cur.fetchone()[0]

    write_image(data)

except sqlite3.Error as err:
    print 'Error {}:'.format(err.args[0])
    sys.exit(1)

finally:
    if con:
        con.close()
