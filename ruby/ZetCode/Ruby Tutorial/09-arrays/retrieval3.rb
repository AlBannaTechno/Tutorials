#!/usr/bin/env ruby

lts = %w{ a b c d e f g h }

puts lts.values_at(1..5).inspect
puts lts.values_at(1, 3, 5).inspect
puts lts.values_at(1, 3, 5, 6, 8).inspect
puts lts.values_at(-1, -3).inspect
