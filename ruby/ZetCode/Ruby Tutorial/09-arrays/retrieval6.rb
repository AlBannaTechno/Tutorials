#!/usr/bin/env ruby

lts = %w{ a b c d e f g h }

puts lts.slice(0)
puts lts.slice(-1)
puts lts.slice(0, 3).inspect
puts lts.slice(2..6).inspect
puts lts.slice(2...6).inspect
