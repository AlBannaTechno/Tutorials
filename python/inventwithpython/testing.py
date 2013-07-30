#!/usr/bin/env python
# -*- encoding: utf-8 -*-

# Imports
import random

def roll(amount, die):
    print "Rolling %d d%d" % (amount, die)
    for x in xrange(amount):
        print random.randint(1, die),
    print

def dice(die):
    globals()["rd%s"%die] = lambda a: roll(a, die)

map(dice, [20, 12, 10, 8, 6, 4])

rd20(5)
rd12(5)
rd10(5)
rd8(5)
rd6(5)
rd4(5)