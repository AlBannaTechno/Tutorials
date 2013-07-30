#!/usr/bin/env ruby

class Person
    def initialize(name, age)
        @name = name
        @age = age
    end

    def info
        "#{@name} is #{@age} years old"
    end
end

p = Person.new("Jane", 17)
puts p.info

puts "ZetCode".reverse
