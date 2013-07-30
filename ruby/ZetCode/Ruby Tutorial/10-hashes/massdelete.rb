#!/usr/bin/env ruby

names1 = Hash.new

names1[1] = "Jane"
names1[2] = "Thomas"
names1[3] = "Robert"
names1[4] = "Julia"
names1[5] = "Rebecca"

puts names1.reject { |k, v| v =~ /R.*/ }
puts names1
puts names1.delete_if { |k, v| k <= 3 }
puts names1
