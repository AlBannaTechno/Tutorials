#!/usr/bin/env ruby

integers = [1, 2, 3, 4, 5]

integers.length.times { |idx| puts integers[idx] }
integers.each_with_index { |num, idx| puts "value #{num} has index #{idx}" }
