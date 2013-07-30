#!/usr/bin/env python
#-*- encoding: utf-8 -*-


import sqlite3
import sys


con = sqlite3.connect('test.db')
try:
    cur = con.cursor()

    cur.executescript("""
        DROP TABLE IF EXISTS Cars;
        CREATE TABLE Cars(Id INT, Name TEXT, Price INT);
        INSERT INTO Cars VALUES(1, 'Audi', 52642);
        INSERT INTO Cars VALUES(2, 'Mercedes', 57127);
        INSERT INTO Cars VALUES(3, 'Skoda', 9000);
        INSERT INTO Cars VALUES(4, 'Volvo', 29000);
        INSERT INTO Cars VALUES(5, 'Bentley', 350000);
        INSERT INTO Cars VALUES(6, 'Citroen', 21000);
        INSERT INTO Cars VALUES(7, 'Hummer', 41400);
        INSERT INTO Cars VALUES(8, 'Volkswagen', 21600);
    """)
    con.commit()

except sqlite3.Error as err:
    if con:
        con.rollback()

    print 'Error {}'.format(err.args[0])
    sys.exit(1)

finally:
    if con:
        con.close()
