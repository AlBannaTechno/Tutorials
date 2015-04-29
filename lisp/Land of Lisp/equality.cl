;; There are many comparators in cl
;; equal, eql, eq, =, string-equal, and equalp are the most common
;; Conrad's rule of thumb:
;; 1. Use "eq" to compare symbols
;; 2. Use "equal" for everything else

(defparameter *fruit* 'apple)

(cond ((eq *fruit* 'apple) 'its-an-apple)
      ((eq *fruit* 'orange) 'its-an-orange))

;; Equal can compare most things in lisp easily
;; Comparing symbols
(equal 'apply 'apply)
;; lists
(equal (list 1 2 3) '(1 2 3))
;; integers
(equal 5 5)
;; floating point numbers
(equal 2.5 2.5)
;; strings
(equal "foo" "foo")
;; characters
(equal #\a #\a)

;; Eql, although similar to eq, also handles numbers and characters
(eql 'foo 'foo)
(eql 3.4 3.4)
(eql #\a #\a)

;; Equalp is similar to equal, but can ignore things like case or number type
(equalp "Bob Smith" "bob smith")
(equalp 0 0.0)

;; The rest are similar to the above, but are used more for specializations
;; numbers
(= 1 1.0)
;; strings
(string-equal "The World" "the world")
;; and characters
(char-equal #\a #\A)
