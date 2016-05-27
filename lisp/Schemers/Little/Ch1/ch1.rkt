#lang racket


(define (atom? x)
  (and (not (pair? x))
       (not (null? x))))


(atom? 'atom) ;;=> #t - a string of characters
(atom? 'turkey) ;;=> #t - a string of characters
(atom? '1942) ;;=> #t - a string of digits
(atom? 'u) ;;=> #t - a string of one character
(atom? '*abc$) ;;=> #t - a string of characters
(list? '(atom)) ;;=> #t - atom is enclosed by parentheses
(list? '(atom turkey or)) ;;=> #t - collection of atoms enclosed by parentheses
;; (list? (quote (atom turkey) or)) ;;=> no, because there are two s-expr not enclosed
(list? '((atom turkey) or)) ;;=> #t
(atom? 'xyz) ;;=> #t - all atoms are also s-expr
(list? '(x y z)) ;;=> #t - all lists are also s-expr
(list? '((x y) z)) ;;=> #t
(list? '(how are you doing so far)) ;;=> #t
(length '(how are you doing so far)) ;;=> 6
(list? '(((how) are) ((you) (doing so)) far)) ;;=> #t
(length '(((how) are) ((you) (doing so)) far)) ;;=> 3
(list? '()) ;;=> #t
(atom? '()) ;;=> #f - lists are not atoms
(list? '(() () () ())) ;;=> #t


(car '(a b c)) ;;=> 'a - the first atom of the list
(car '((a b c) x y z)) ;;=> '(a b c) - the first s-expr of the list
;; (car '()) ;;=> no, because the list is empty

;; Law of Car: The car of a non-empty list is always the first s-expr

(car '(((hotdogs)) (and) (pickle) relish)) ;;=> '((hotdogs)) - the car (first element) of the list
(car (car '(((hotdogs)) (and)))) ;;=> '(hotdogs)
(cdr '(a b c)) ;;=> '(b c) - cdr is the /rest/ of the list, or without the car of the list
(cdr '((a b c) x y z)) ;;=> '(x y z)
(cdr '(hamburger)) ;;=> '()
(cdr '((x) t r)) ;;=> '(t r)
;; (cdr 'a) ;;=> no because you can't ask for the cdr of an atom
;; (cdr '()) ;;=> no because you can't ask for the cdr of a null list

;; Law of Cdr: The cdr of a non-empty list is always the rest of the list beyond the first item

(car (cdr '((b) (x y) ((c))))) ;;=> '(x y) - the first item of the rest of the list
(cdr (cdr '((b) (x y) ((c))))) ;;=> '(((c))) - the rest of the rest of the list
;; (cdr (car '(a (b (c)) d))) ;;=> no because you can't call cdr on an atom


(cons 'a '(butter and jelly)) ;;=> '(a butter and jelly) - cons adds to the start of a list
(cons '(banana and) '(peanut butter and jelly)) ;;=> '((banana and) peanut butter and jelly)
(cons '((help) this) '(is very ((hard) to learn))) ;;=> '(((help) this) is very ((hard) to learn))
;; Cons takes any s-expr and a list to form a new list
(cons '(a b (c)) '()) ;;=> '((a b (c))) - '() is still a list
(cons 'a '()) ;;=> '(a)
;; (cons '((a b c)) 'b) ;;=> no because the second argument must be a list
;; (cons 'a 'b) ;;=> no because the second argument isn't a list

;; Law of Cons: takes two arguments, the second must be a list and the result is a list

(cons 's (car '((b) c d))) ;;=> '(s b) - first item of the list is a list that can be added to
(cons 's (cdr '((b) c d))) ;;=> '(s c d) - cdr returns the rest as a list that can be added to
(null? '()) ;;=> #t - an empty list is considered to be null
(null? (quote ())) ;;=> #t - (quote ()) is also known as a null list
(null? '(a b c)) ;;=> #f - non empty lists are not null
(null? 'spaghetti) ;;=> #f - atoms are not null

;; Law of Null?: only an empty list counts as null

(equal? (atom? 'Harry) #t) ;;=> #t - string of characters beginning with a letter
(atom? 'Harry) ;;=> #t
(atom? '(Harry had a heap of apples)) ;;=> #f
;; Atom takes one argument that can be any s-expr
(atom? (car '(Harry had a heap of apples))) ;;=> #t
(atom? (cdr '(Harry had a heap of apples))) ;;=> #f - return is a list
(atom? (cdr '(Harry))) ;;=> #f - return is null
(atom? (car (cdr '(swing low sweet cherry oat)))) ;;=> #t
(atom? (car (cdr '(swing (low sweet) cherry oat)))) ;;=> #f - return is a list

(eq? 'Harry 'Harry) ;;=> #t - eq? checks if the two are identical atoms
(eq? 'margarine 'butter) ;;=> #f - they are different atoms
;; eq? takes two non-numeric atoms
(eq? '() '(strawberry)) ;;=> #f - both arguments are lists
