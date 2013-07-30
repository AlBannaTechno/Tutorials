#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# zerodivision.py

def input_numbers():
    a = float(raw_input("Enter first number:"))
    b = float(raw_input("Enter second number:"))
    return a, b

x, y = input_numbers()
print "%d / %d is %f" % (x, y, x/y)