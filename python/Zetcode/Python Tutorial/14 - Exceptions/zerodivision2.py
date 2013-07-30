#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# zerodivision2.py

def input_numbers():
    a = float(raw_input("Enter first number: "))
    b = float(raw_input("Enter second number: "))
    return a, b

x, y = input_numbers()

while True:
    if y != 0:
        print "%d / %d is %f" % (x, y, x/y)
        break
    else:
        print "Cannot divide by zero"
        x, y = input_numbers()