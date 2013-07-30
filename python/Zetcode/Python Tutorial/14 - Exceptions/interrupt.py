#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# interrupt.py

try:
    while True:
        pass
except KeyboardInterrupt:
    print "Program Interrupted"

try:
    while True:
        pass
except BaseException:
    print "Program Interrupted"