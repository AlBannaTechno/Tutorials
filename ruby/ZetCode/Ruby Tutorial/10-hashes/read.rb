#!/usr/bin/env ruby

stones = { 1 => "garnet", 2 => "topaz", 3 => "opal", 4 => "amethyst" }

puts stones.fetch(1)
puts stones[2]
puts stones.values_at(1, 2, 3)
