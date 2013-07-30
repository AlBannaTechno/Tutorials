#!/usr/bin/env ruby

str = "1,2,3,4,5,6,7"
p str.split

$; = ","  # used when split is called
p str.split
