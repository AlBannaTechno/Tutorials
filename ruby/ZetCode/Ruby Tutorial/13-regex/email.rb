#!/usr/bin/env ruby

emails = %w{ luke@gmail.com andy@yahoo.com 23214sdj^as f3444@gmail.com }
pattern = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9-]+\.[a-zA-Z.]{2,5}$/

emails.each do |email|
    if email.match(pattern)
        puts "#{email} matches"
    else
        puts "#{email} does not match"
    end
end
