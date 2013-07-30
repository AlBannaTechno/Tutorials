#!/usr/bin/env ruby

lts = %w{a b c d e f g h}

lts.pop
lts.pop

puts lts.inspect

lts.shift
lts.shift

puts lts.inspect

lts.delete_at(0)
lts.delete('d')

puts lts.inspect

puts lts.clear
puts lts.inspect
