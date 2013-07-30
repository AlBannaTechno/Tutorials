#!/usr/bin/env ruby

puts "%.*f" % [3, 1.1111111]
puts "%0*d" % [10, 2]
puts "%0*.*f" % [10, 3, 1.1111]
