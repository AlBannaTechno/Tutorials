#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# zerodivision3.py

def input_numbers():
    a = float(raw_input("Enter first number: "))
    b = float(raw_input("Enter second number: "))
    return a, b

x, y = input_numbers()

while True:
    try:
        print "%d / %d is %f" % (x, y, x/y)
        break
    except ZeroDivisionError:
        print "Cannot divide by zero"
        x, y = input_numbers()