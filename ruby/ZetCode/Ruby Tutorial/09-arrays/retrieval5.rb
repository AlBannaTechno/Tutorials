#!/usr/bin/env ruby

lts = %w{ a b c d e f g h }

puts lts.take(4).inspect

lts2 = lts.take_while { |e| e < 'f' }
puts lts2.inspect
