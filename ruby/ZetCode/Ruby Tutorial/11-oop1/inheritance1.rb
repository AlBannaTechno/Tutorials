#!/usr/bin/env ruby

class Being
    def initialize
        puts "Being class created"
    end
end

class Human < Being
    def initialize
        super
        puts "Human class created"
    end
end

Being.new
Human.new
