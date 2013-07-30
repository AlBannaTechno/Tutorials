#!/usr/bin/env ruby

class Being
    def to_s
        "This is Being"
    end

    def get_id
        9
    end
end

class Living < Being
    def to_s
        "This is Living"
    end
end

l = Living.new

puts l
puts l.get_id
puts l.is_a? Being
puts l.is_a? Object
puts l.is_a? BasicObject
