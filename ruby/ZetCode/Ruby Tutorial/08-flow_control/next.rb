#!/usr/bin/env ruby

num = 0
while num < 100
    num += 1

    if (num % 2 == 0)
        next
    end

    print "#{num} "
end

puts
