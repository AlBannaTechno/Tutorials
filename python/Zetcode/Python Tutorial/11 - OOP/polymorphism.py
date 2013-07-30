#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# polymorphism.py

class Animal:
    def __init__(self, name=""):
        self.name = name

    def talk(self):
        pass


class Cat(Animal):
    def talk(self):
        print "Meow!"


class Dog(Animal):
    def talk(self):
        print "Woof!"


a = Animal()
a.talk()

b = Cat("Missy")
b.talk()

c = Dog("Rocky")
c.talk()