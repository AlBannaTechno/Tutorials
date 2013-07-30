#!/usr/bin/env ruby

@name = "Jane"
@age = 17

def info
    "#{@name} is #{@age} years old"
end

puts self.instance_variables
puts self.private_methods.include? :info

puts info
