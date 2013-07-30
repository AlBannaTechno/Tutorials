#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# reference.py

n = [1, 2, 3, 4, 5]

print "Original List: ", n

def function1(x):
    x.pop()
    x.pop()
    x.insert(0, 0)
    print "Inside function1: ", x


function1(n)
print "After function call: ", n