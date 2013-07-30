#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# zero.py

try:
    3/0
except ZeroDivisionError, err:
    print "Cannot divide by zero"
    print "Message: ", err.message
    print "Class: ", err.__class__