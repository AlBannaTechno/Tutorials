#lang planet neil/sicp
#|
Chapter 1 Exercise 1.8 of SICP

Implement a cube-root procedure analogous to the square-root procedure.
|#


(define (square x)
  (* x x))

(define (cube x)
  (* x x x))

(define (good-enough? guess x improve)
  (< (abs (- (improve guess x) guess))
     (abs (* guess 0.001))))

(define (root-iter guess x improve)
  (if (good-enough? guess x improve)
      guess
      (root-iter (improve guess x) x improve)))

(define (sqrt-improve guess x)
  (/ (+ guess (/ x guess)) 2))

(define (cbrt-improve guess x)
  (/ (+ (/ x (square guess))
        (* 2 guess))
     3))

(define (sqrt x)
  (root-iter 1.0 x sqrt-improve))

(define (cbrt x)
  (root-iter 1.0 x cbrt-improve))
