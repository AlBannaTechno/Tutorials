#!/usr/bin/env ruby

names1 = Hash.new

names1[1] = "Jane"
names1[2] = "Thomas"
names1[3] = "Robert"
names1[4] = "Julia"
names1[5] = "Rebecca"

names2 = names1.dup

puts names1.eql?(names2)

puts names1.empty?
names1.clear
puts names1.empty?
