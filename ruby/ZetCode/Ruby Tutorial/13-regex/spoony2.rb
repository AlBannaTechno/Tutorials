#!/usr/bin/env ruby

p "car".match %r{ [abc][a][rs] }
p "car".match(/[a-r]/)
p "23af 433a 4ga".scan(/\b[a-f0-9]+\b/)
