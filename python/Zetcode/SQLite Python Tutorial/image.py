#!/usr/bin/env python
#-*- encoding: utf-8 -*-


import sqlite3
import sys


def read_image():
    fin = 0

    try:
        fin = open('woman.jpg', 'rb')
        img = fin.read()
        return img

    except IOError as err:
        print 'Error {}: {}'.format(err.args[0], err.args[1])
        sys.exit(1)

    finally:
        if fin:
            fin.close()

con = 0
try:
    con = sqlite3.connect('test.db')
    cur = con.cursor()
    data = read_image()
    binary = sqlite3.Binary(data)
    cur.execute('INSERT INTO Images(Data) VALUES (?)', (binary,))
    con.commit()

except sqlite3.Error as err:
    if con:
        con.rollback()

    print 'Error {}:'.format(err.args[0])
    sys.exit(1)

finally:
    if con:
        con.close()
