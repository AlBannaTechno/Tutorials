#!/usr/bin/env ruby

lts = %w{ a b c d e f }

puts lts.inspect
puts "Array has #{lts.length} elements"
puts "The first element is #{lts.first}"
puts "The last element is #{lts.last}"

puts lts.eql? lts.dup
puts lts.eql? lts.dup.delete_at(0)

lts.clear
puts lts.inspect
puts lts.empty?
