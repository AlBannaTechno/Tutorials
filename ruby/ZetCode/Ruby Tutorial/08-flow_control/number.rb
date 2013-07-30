#!/usr/bin/env ruby

print "Enter a number: "
num = gets.to_i

if num < 0
    puts "#{num} is negative"
elsif num == 0
    puts "#{num} is zero"
elsif num > 0
    puts "#{num} is positive"
end
