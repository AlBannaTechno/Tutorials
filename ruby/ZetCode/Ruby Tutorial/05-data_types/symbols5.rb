#!/usr/bin/env ruby

def info
    "info method"
end

@v = "Ruby"
@@n = "16"

p Symbol.all_symbols.include? :info
p Symbol.all_symbols.include? :@v
p Symbol.all_symbols.include? :@@n
