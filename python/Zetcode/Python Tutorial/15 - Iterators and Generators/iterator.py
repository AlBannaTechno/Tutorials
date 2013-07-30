#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# iterator.py

class seq:
    def __init__(self):
        self.x = 0

    def next(self):
        self.x += 1
        return self.x ** self.x

    def __iter__(self):
        return self


s = seq()
n = 0

for i in s:
    print i
    n += 1
    if n > 10:
        break