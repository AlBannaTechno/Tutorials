;; full of random stuff from chapter 11

;; The first parameter to format is the destination. true will print, where nil will return a string

(format t "Add onion rings for only ~$ dollars more!" 1.5)
(princ (reverse (format nil "Add onion rings for only ~$ dollars more!" 1.5)))

;; For prin1 behavior use ~s
(format t "I am printing ~s in the middle of this sentence." "foo")
;; And for princ behavior use ~a
(format t "I am printing ~a in the middle of this sentence." "foo")

;; Padding!
(format t "I am printing ~10a within 10 spaces of room." "foo")  ; right
(format t "I am printing ~10@a within 10 spaces of room." "foo")  ; left

;; Second param is how padding is added in groups
(format t "I am printing ~10,3a within ten (or more) spaces of room." "foo")
;; Third param is an exact amount of padding added after the value is
(format t "I am printing ~,,4a in the middle of this sentence." "foo")
;; And the fourth param is to specify a character to use for padding (space is default)
(format t "The word ~,,4,'!a feels very important" "foo")

;; And of course you can use @ to place it on the left side
(format t "The word ~,,4,'!@a feels very important" "foo")

;; Time for numbers!

;; x for hex, b for binary, d for decimal
(format t "The number 1000 in hex is ~x" 1000)
(format t "The number 1000 in binary is ~b" 1000)
(format t "The number 1000 in decimal is ~d" 1000)

;; To make format use commas use :
(format t "Numbers with commas in them are ~:d times better" 1000000)

;; First parameter is padding, second is the padding character
(format t "I am printing ~10d within ten spaces of room" 1000000)
(format t "I am printing ~10,'xd within ten spaces of room" 1000000)

;; f is used for floating point numbers;
;; The first param is the number of characters displayed
;; The second param is the number of digits displayed
(format t "PI can be estimated as ~4f" 3.141593)
(format t "PI can be estimated as ~,4f" pi)

;; And of course, as above, $ can be used for currencies
(format t "I wish I had ~$ dollars in my bank account." 1000000.2)

;; Lisp has 2 main ways of printing a new line
;; terpri forces a new line no matter what
(progn (princ 22)
       (terpri)
       (princ 33))
;; Whereas fresh-line will only print a newline if required (ie not already on a new line)
(progn (princ 22)
       (fresh-line)
       (fresh-line)
       (princ 33))

;; The format equivalents of these are % (terpri) and & (fresh-line)
(progn (format t "this is on one line ~%")
       (format t "~%this is on another line"))
(progn (format t "this is on one line ~&")
       (format t "~&this is on another line"))

;; The first parameter to these is the number of new lines to print
(format t "This will print ~5%on two lines spread far apart")

;; Justification-izing!
(defun random-animal ()
  (nth (random 5) '("dog" "tick" "tiger" "walrus" "kangaroo")))

;; t controls the column position of items
(loop repeat 10
   do (format t "~5t~a ~15t~a ~25t~a~%"
              (random-animal)
              (random-animal)
              (random-animal)))

;; < and > will allow for equal spacing
(loop repeat 10
   do (format t "~30<~a~;~a~;~a~>~%"
              (random-animal)
              (random-animal)
              (random-animal)))
;; explanation:
;;    1  2 3 2 3 2 4 5
;; "~30<~a~;~a~;~a~>~%"
;; 1: "~30<" start justifying
;; 2: "~a" three values placed inside
;; 3: "~;" start new item to justify
;; 4: "~>" stop justifying
;; 5: new line

;; single center column with @
(loop repeat 10
   do (format t "~30:@<~a~>~%" (random-animal)))

;; And now to fix the above a bit (kinda)
(loop repeat 10
   do (format t "~30:@<~a~;~a~;~a~>~%"
              (random-animal)
              (random-animal)
              (random-animal)))

;; And now adding in justification
(loop repeat 10
   do (format t "~10:@<~a~>~10:@<~a~>~10:@<~a~>~%"
              (random-animal)
              (random-animal)
              (random-animal)))
