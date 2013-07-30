#!/usr/bin/env ruby

chars = %w{a b c d e}

reversed_chars = chars.reverse
puts reversed_chars.inspect
puts chars.inspect

reversed_chars = chars.reverse!
puts reversed_chars.inspect
puts chars.inspect
