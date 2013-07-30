#!/usr/bin/env ruby

website = "zetcode.com"

website.each_char do |c|
    print "#{c} has ASCII code %d\n" % c.ord
end
