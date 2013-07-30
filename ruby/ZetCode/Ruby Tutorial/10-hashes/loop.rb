#!/usr/bin/env ruby

stones = { 1 => "garnet", 2 => "topaz", 3 => "opal", 4 => "amethyst" }

stones.each { |k, v| puts "Key: #{k}, Value: #{v}" }
stones.each_key { |key| puts "#{key}" }
stones.each_value { |val| puts "#{val}" }
stones.each_pair { |k, v| puts "Key: #{k}, Value: #{v}" }
