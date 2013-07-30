#!/usr/bin/env ruby

nums = (4..50).to_a

puts "Prime Numbers:"

print "2 3 "

nums.each do |i|
    not_prime = false

    (2..Math.sqrt(i).ceil).each do |j|
        not_prime = true if i % j == 0
    end

    print i, " " unless not_prime
end

puts
