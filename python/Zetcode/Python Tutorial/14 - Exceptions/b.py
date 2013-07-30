#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# b.py

class BFoundError(Exception):
    def __init__(self, value):
        print "BFoundError: b character found at position %d" % value

string = "You make me want to be a better man."

pos = 0
for i in string:
    if i == 'b':
        raise BFoundError, pos
    pos += 1