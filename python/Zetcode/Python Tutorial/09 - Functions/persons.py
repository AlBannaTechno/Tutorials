#!/usr/bin/env python
# -*- encoding; utf-8 -*-
# persons.py

def display(name, age, sex):
    print "Name: ", name
    print "Age: ", age
    print "Sex: ", sex

display("Larry", 43, "M")
display("Joan", 24, "F")

display(age=43, name="Larry", sex="M")
display(name="Joan", age=24, sex="F")