#!/usr/bin/env ruby

nms = [2, -1, -4, 0, 4, 3, -2, 3, 5]
nms.delete_if { |x| x < 0 }

puts nms.inspect
