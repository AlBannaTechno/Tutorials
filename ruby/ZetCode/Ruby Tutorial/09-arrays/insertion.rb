#!/usr/bin/env ruby

lts = []

lts.insert(0, 'E', 'F', 'G')
lts.push('H')
lts.push('I', 'J', 'K')
lts << 'L' << 'M'
lts.unshift('A', 'B', 'C')
lts.insert(3, 'D')

puts lts.inspect
