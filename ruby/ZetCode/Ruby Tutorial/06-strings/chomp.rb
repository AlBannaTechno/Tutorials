#!/usr/bin/env ruby

print "Are you sure you want to download? (Yes/No) "

response = gets

if (response.downcase.chomp == "yes")
    puts "Downloaded"
else
    puts "Download Canceled"
end

puts response.inspect
