#!/usr/bin/env ruby

re = Regexp.new("Jane")
p "Jane is hot".match(re)

p "Jane is hot" =~ /Jane/
p "Jane is hot".match %r{Jane}
