#!/usr/bin/env ruby

module ModuleM
    m1, m2 = 4

    puts "Inside module"
    puts local_variables
end

def method1
    v, w = 3
    puts "Inside method"
    puts local_variables
end

class Some
    x, y = 2
    puts "Inside class"
    puts local_variables
end

method1
t1, t2 = 7
puts "Inside toplevel"
puts local_variables
