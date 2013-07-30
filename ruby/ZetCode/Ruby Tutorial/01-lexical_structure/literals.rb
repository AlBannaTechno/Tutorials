#!/usr/bin/env ruby

require "date"

sng = true
name = "James"
job = nil
weight = 68.5
born = Date.parse("November 12, 1986")

puts "His name is #{name}"

if sng == true
    puts "He is single"
else
    puts "He is in a relationship"
end

puts "His job is #{job}"
puts "He weighs #{weight} kilograms"
puts "He was born in #{born}"
