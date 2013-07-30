#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# cleanup.py

try:
    f = file("indaclub", 'r')
    contents = f.readlines()
    for i in contents:
        print i,

except IOError:
    print "Error opening file"

finally:
    if f:
        f.close()