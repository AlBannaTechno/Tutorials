#!/usr/bin/env ruby

names = Hash.new

names[1] = "Jane"
names[2] = "Thomas"
names[3] = "Robert"
names[4] = "Julia"
names[5] = "Rebecca"

names.delete(4)
names.shift

puts names
