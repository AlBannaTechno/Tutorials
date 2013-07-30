#!/usr/bin/env ruby

class Base
    def show(x=0, y=0)
        p "Base class, x: #{x}, #{y}"
    end
end

class Derived < Base
    def show(x, y)
        super  # passed arguments given to this method
        super(x)
        super(x, y)
        super()  # passes no arguments
    end
end

d = Derived.new
d.show(3, 3)
