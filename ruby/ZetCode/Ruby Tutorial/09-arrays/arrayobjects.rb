#!/usr/bin/env ruby

class Empty

end

nums = [1, 2, 3, 4, 5]
various = [1, -1, "big", 3.4, Empty.new, nums, :two]

puts various.inspect
