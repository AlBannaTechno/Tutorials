#!/usr/bin/env ruby

class Being
end

class Living < Being
end

class Mammal < Living
end

class Human < Mammal
end

p Human.ancestors
