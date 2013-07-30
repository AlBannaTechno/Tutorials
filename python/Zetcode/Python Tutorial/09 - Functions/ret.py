#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# ret.py

"""
The ret.py script shows how to work with functions in Python.
"""

def showModuleName():
    print __doc__

def getModuleFile():
    return __file__

a = showModuleName()
b = getModuleFile()

print a, b