#!/usr/bin/env ruby

text = "The cat also known as the domestic cat is a small, usually furry, domesticated, "
       "carnivorous mammal."

p text.scan(/\bcat\b/)

p $`
p $&
p $'
