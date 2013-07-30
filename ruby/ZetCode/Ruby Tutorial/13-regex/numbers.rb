#!/usr/bin/env ruby

nums = %w{ 234 1 23 53434 234532453464 23455636 324f 34532452343452 343 2324 24221 34$34232 }

nums.each do |num|
    n = num.match(/[0-9]+/)
    if n.to_s.eql?(num)
        puts num
    end
end
