#!/usr/bin/env ruby

p "color colour colors colours".scan(/colou?rs/)
p "color colour colors colours".scan(/colou?rs?/)
p "color colour colors colours".scan(/\bcolor\b|\bcolors\b|\bcolour\b|\bcolours\b/)
