#!/usr/bin/env ruby

puts "motherboard" =~ /board/
puts "12, 911, 12, 111"[/\d{3}/]

puts "motherboard".gsub(/board/, "land")

p "meet the deep nil need".scan(/.[e][e]./)
p "This is Sparta!".split(/\s/)
