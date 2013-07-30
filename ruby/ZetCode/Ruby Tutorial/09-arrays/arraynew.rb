#!/usr/bin/env ruby

a1 = Array.new
a2 = Array.new(3)
a3 = Array.new(6, "coin")
a4 = Array.new([11])
a5 = Array.new(15) { |e| e * e }

puts [a1, a2, a3, a4, a5].inspect
