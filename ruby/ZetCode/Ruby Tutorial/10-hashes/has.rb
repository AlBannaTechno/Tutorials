#!/usr/bin/env ruby

domains = { :de => "Germany", :sk => "Slovakia", :no => "Norway",  :us => "United States" }

puts domains.has_key?(:de)
puts domains.include?(:no)
puts domains.key?(:me)
puts domains.member?(:sk)

puts domains.has_value?("Slovakia")
puts domains.value?("Germany")
