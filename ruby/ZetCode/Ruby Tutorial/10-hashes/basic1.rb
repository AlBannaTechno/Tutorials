#!/usr/bin/env ruby

names = Hash.new

names[1] = "Jane"
names[2] = "Thomas"
names[3] = "Robert"
names[4] = "Julia"
names[5] = "Rebecca"

puts "The size of the hash is #{names.size}"

puts names.keys.inspect
puts names.values.inspect
