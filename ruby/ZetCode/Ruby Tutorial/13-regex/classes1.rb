#!/usr/bin/env ruby

words = %w{ sit MIT fit fat lot pad }
pattern = /[fs]it/

words.each do |word|
    if word.match pattern
        puts "#{word} matches the pattern"
    else
        puts "#{word} does not match the pattern"
    end
end
