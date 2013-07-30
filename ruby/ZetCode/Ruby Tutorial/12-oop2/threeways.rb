#!/usr/bin/env ruby

class Wood
    def info
        "This is a Wood object"
    end
end

wood = Wood.new
p wood.info

class Brick
    attr_accessor :info
end

brick = Brick.new
brick.info = "This is a Brick object"
p brick.info

class Rock
end

rock = Rock.new

def rock.info
    "This is a Rock object"
end

p rock.info
