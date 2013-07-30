#!/usr/bin/env ruby

lts = %w{ a b c d e f g h }

puts lts[0]
puts lts[-1]
puts lts[0, 3].inspect
puts lts[2..6].inspect
puts lts[2...6].inspect
