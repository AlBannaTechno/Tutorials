#!/usr/bin/env ruby

word = "Determination"

puts "The word #{word} has #{word.size} characters"

puts word.include? "tion"
puts word.include? "tic"

puts

puts word.empty?
word.clear
puts word.empty?
