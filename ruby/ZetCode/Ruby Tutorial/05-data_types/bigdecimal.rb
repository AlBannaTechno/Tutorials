#!/usr/bin/env ruby

require "bigdecimal"

sum = 0

1000.times do
    sum += 0.0001
end

p sum

sum = BigDecimal.new("0")

1000.times do
    sum += BigDecimal.new("0.0001")
end

puts sum.to_s("F")
puts sum.to_s("E")
