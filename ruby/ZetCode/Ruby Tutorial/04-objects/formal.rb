#!/usr/bin/env ruby

s1 = String.new("Ruby")
puts s1.size
puts s1.downcase

a1 = Array.new
a1.push(1, 2, 3)
puts a1.include? 3
puts a1.empty?

r1 = Range.new(1, 6)
puts r1.class
puts r1.include? 4
