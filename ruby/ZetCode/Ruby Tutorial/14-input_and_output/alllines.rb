#!/usr/bin/env ruby

fname = "alllines.rb"

File.readlines(fname).each { |line| puts line }
