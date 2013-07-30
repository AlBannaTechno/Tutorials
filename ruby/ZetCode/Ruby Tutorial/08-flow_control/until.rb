#!/usr/bin/env ruby

hours_left = 12

until hours_left == 0
    if hours_left == 1
        puts "There is #{hours_left} hour left"
    else
        puts "THere are #{hours_left} hours left"
    end

    hours_left -= 1
end
