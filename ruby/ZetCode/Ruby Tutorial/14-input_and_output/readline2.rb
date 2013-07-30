#!/usr/bin/env ruby

f = File.open("stones")
while line = f.gets do
    puts line
end
f.close
