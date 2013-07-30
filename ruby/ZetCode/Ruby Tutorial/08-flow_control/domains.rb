#!/usr/bin/env ruby

print "Enter top level domain: "
domain = gets.chomp

case domain
when "us"
    puts "United States"
when "de"
    puts "Germany"
when "sk"
    puts "Slovakia"
when "hu"
    puts "Hungary"
else
    puts "Unknown"
end
