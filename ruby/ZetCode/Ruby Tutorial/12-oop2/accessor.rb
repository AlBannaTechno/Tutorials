#!/usr/bin/env ruby

class Book
    attr_accessor :title, :pages
end

b1 = Book.new
b1.title = "Hidden Motives"
b1.pages = 255

p "The book #{b1.title} has #{b1.pages} pages"
