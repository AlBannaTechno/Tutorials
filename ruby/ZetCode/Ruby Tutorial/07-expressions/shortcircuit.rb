#!/usr/bin/env ruby

def one
    puts "Inside one"
    false
end

def two
    puts "Inside two"
    true
end

puts "Short Circuit"

if one && two
    puts "Pass"
end

puts "#############"

if two || one
    puts "Pass"
end
