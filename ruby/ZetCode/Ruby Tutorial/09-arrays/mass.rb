#!/usr/bin/env ruby

nums = [1, 3, 2, 6, 7, 12, 8, 15]
selected = nums.select { |e| e > 10 }

puts selected.inspect

collected = nums.collect { |e| e < 10 }

puts collected.inspect

mapped = nums.map { |e| e * 2 }

puts mapped.inspect
