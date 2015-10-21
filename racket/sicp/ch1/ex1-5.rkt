#lang planet neil/sicp
#|
Chapter 1 Exercise 1.5 of SICP

Expand the given code in both applicative-order and normal-order evaluation.
|#


(define (p) (p))

(define (test x y)
  (if (= x 0)
      0
      y))

(test 0 (p))

#|
Applicative-order would never finish, it would be (test 0 (p)) constantly.

Normal-order would evaluate step by step:
(test 0 (p))
(if (= 0 0) 0 (p))
(if #t 0 (p))
0
|#
