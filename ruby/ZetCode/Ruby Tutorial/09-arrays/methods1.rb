#!/usr/bin/env ruby

numbers = [1, 2, 2, 2, 3, 4, 5, 8, 11]

puts numbers.index(2)
puts numbers.index(11)
puts numbers.rindex(2)

puts numbers.include?(3)
puts numbers.include?(10)

puts numbers.join('-')
puts numbers.uniq!.inspect
