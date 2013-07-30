#!/usr/bin/env ruby

lts = %w{a b c d e f g}

puts lts.inspect

lts.reject! do |e|
    e =~ /[c-y]/
end

puts lts.inspect

lts.replace(['x', 'y', 'z'])
puts lts.inspect
