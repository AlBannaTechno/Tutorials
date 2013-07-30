#!/usr/bin/env ruby

lts = [0, 1, 2, 3, 4, 5, 6]

puts lts.fetch(0)
puts lts.fetch(-2)
puts lts.fetch(8, "undefined")
puts lts.fetch(8) { |e| -2 * e }
