#lang planet neil/sicp
#|
Chapter 1 Exercise 1.6 of SICP

Explain what happens when using "new-if" and why.
|#


(define (new-if predicate then-clause else-clause)
  (cond (predicate then-clause)
        (else else-clause)))

;; Tests
(new-if (= 2 3) 0 5)  ;;=> 5
(new-if (= 1 1) 0 5)  ;;=> 0

;; Square root finder
(define (sqrt-iter guess x)
  (new-if (good-enough? guess x)
          guess
          (sqrt-iter (improve guess x) x)))

(define (improve guess x)
  (average guess (/ x guess)))

(define (average x y)
  (/ (+ x y) 2))

(define (good-enough? guess x)
  (< (abs (- (square guess) x)) 0.001))

(define (square x)
  (* x x))

(define (sqrt x)
  (sqrt-iter 1.0 x))

#|
The main difference here is that if will not evaluate both expressions, whereas new-if will.
|#
