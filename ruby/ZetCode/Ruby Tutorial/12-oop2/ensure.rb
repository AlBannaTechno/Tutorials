#!/usr/bin/env ruby

begin
    f = File.open("stones", "r")

    while line = f.gets do
        puts line
    end
rescue => e
    puts e
    p e
ensure
    f.close if f
end
