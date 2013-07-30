#!/usr/bin/env ruby

"Her name is Jane" =~ /name/

p $`  # string preceeding $&
p $&  # string that matched the last regular expression match
p $'  # string following $&
