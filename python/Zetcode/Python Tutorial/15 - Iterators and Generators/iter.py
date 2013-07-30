#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# iter.py

str = "formidable"

for i in str:
    print i,

print

it = iter(str)

print it.next()
print it.next()
print it.next()

print list(it)