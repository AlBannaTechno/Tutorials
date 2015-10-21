#lang planet neil/sicp
#|
Chapter 1 Exercise 1.4 of SICP

Describe the behavour of the given procedure.
|#


(define (a-plus-abs-b a b)
  ((if (> b 0) + -) a b))
;; The if statement returns an operator which is applied to the operands.
