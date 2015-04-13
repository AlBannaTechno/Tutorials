#lang racket
(require rackunit)


(check-equal? (add1 5) 6)
(check-equal? (add1 5) 7)
;; Exploring the behaviour of a function is not testing
(check-equal? (sub1 (add1 5)) 7)

(check-equal? 5 6 "Numbers matter!")
