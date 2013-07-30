#!/usr/bin/env ruby

File.open("langs", 'w') do |f|
    f.puts "Ruby"
    f.write "Java\n"
    f << "Python\n"
end
