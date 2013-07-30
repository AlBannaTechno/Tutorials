#!/usr/bin/env ruby

x = 35
y = 0

begin
    z = x / y
    puts z
rescue => e
    puts e
    p e
end
