#!/usr/bin/env ruby

Dir.mkdir("tmp")
puts Dir.exists?("tmp")

puts Dir.pwd
Dir.chdir("tmp")
puts Dir.pwd

Dir.chdir("..")
puts Dir.pwd
Dir.rmdir("tmp")
puts Dir.exists?("tmp")
