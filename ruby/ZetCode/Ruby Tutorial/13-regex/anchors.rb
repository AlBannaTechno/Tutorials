#!/usr/bin/env ruby

sen1 = "Everywhere I look I see Jane"
sen2 = "Jane is the best thing that happened to me"

p sen1.match(/^Jane/)
p sen2.match(/^Jane/)

p sen1.match(/Jane$/)
p sen2.match(/Jane$/)
