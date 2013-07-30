#!/usr/bin/env ruby

names = %w{ Jane Thomas Robert Lucy Becky John Peter Andy }
pattern = /Jane|Becky|Robert/

names.each do |name|
    if name =~ pattern
        puts "#{name} is my friend"
    else
        puts "#{name} is not my friend"
    end
end
