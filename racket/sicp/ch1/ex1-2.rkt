#lang planet neil/sicp
#|
Chapter 1 Exercise 1.2 of SICP

Translation of
5 + 4 + (2 - (3 - (6 + 4/5)))
-----------------------------
       3(6 - 2)(2 - 7)
into prefix form
|#


(/ (+ 5 4 (- 2 (- 3 (+ 6 (/ 4 5)))))
   (* 3 (- 6 2) (- 2 7)))
