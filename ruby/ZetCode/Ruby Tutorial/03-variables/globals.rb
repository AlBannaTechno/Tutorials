#!/usr/bin/env ruby

$gb = 6

module ModuleM
    puts "Inside module"
    puts $gb
end

def method1
    puts "Inside method"
    puts $gb
end

class Some
    puts "Inside class"
    puts $gb
end

method1
puts "Inside toplevel"
puts $gb
puts global_variables.include? :$gb
