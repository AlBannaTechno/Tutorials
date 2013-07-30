#!/usr/bin/env python
#-*- encoding: utf-8 -*-


import sqlite3
import sys


def read_data():
    with open('cars.sql', 'r') as file:
        data = file.read()
        return data

with sqlite3.connect('test.db') as con:
    cur = con.cursor()
    sql = read_data()

    cur.execute('DROP TABLE IF EXISTS Cars')
    cur.executescript(sql)
    cur.execute('SELECT * FROM Cars')

    rows = cur.fetchall()
    for row in rows:
        print row
