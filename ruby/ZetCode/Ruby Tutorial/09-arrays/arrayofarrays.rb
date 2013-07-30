#!/usr/bin/env ruby

numbers = [1, 2, 3, [2, 4, 6, [11, 12]]]

puts numbers.length
puts numbers[0], numbers[1]

puts numbers[3][0]
puts numbers[3][1]

puts numbers[3][3][0]
puts numbers[3][3][1]

puts numbers.flatten!.inspect
