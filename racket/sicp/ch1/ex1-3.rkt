#lang planet neil/sicp
#|
Chapter 1 Exercise 1.3 of SICP

Define a procedure that takes three numbers as arguments and returns the sum of the squares of the
two larger numbers.
|#


(define (square x)
  (* x x))

(define (sum-of-squares x y)
  (+ (square x) (square y)))

(define (square-sum-of-largest-two x y z)
  (cond ((= (min x y z) x) (sum-of-squares y z))
        ((= (min x y z) y) (sum-of-squares x z))
        ((= (min x y z) z) (sum-of-squares x y))))
