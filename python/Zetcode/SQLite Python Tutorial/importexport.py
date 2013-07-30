#!/usr/bin/env python
#-*- encoding:utf-8 -*-


import sqlite3
import sys


cars = (
    (1, 'Audi', 52643),
    (2, 'Mercedes', 57642),
    (3, 'Skoda', 9000),
    (4, 'Volvo', 29000),
    (5, 'Bentley', 350000),
    (6, 'Hummer', 41400),
    (7, 'Volkswagen', 21600) )

def write_data(data):
    with open('cars.sql', 'w') as file:
        file.write(data)

with sqlite3.connect(':memory:') as con:
    cur = con.cursor()
    cur.execute('DROP TABLE IF EXISTS Cars')
    cur.execute('CREATE TABLE Cars(Id INT, Name TEXT, Price INT)')
    cur.executemany('INSERT INTO Cars VALUES(?, ?, ?)', cars)
    cur.execute('DELETE FROM Cars WHERE Price < 30000')

    data = '\n'.join(con.iterdump())

    write_data(data)
