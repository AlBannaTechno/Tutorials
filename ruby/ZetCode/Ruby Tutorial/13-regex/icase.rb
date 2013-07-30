#!/usr/bin/env ruby

p "Jane".match(/Jane/)
p "Jane".match(/jane/)
p "Jane".match(/JANE/)

p "Jane".match(/Jane/i)
p "Jane".match(/jane/i)
p "Jane".match(/JANE/i)
