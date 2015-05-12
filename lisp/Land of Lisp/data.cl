(cons 1 (cons 2 3))
;;=> (1 2 . 3)

;; equivalent to (1 2 3)
'(1 . (2 . (3 . nil)))


;; cons cells can be used for pairs
(cons 2 3)
;;=> (2 . 3)


;; circular lists can be created, and are dangerous!
;; remember to set this first!
(setf *print-circle* t)

(defparameter foo '(1 2 3))
(setf (cddr foo) foo)
;;=> #1=(1 2 3 . #1#)


;; Cons cells work well for association lists, or key value pairs
(defparameter *drink-order*
  '((bill . double-espresso)
    (lisa . small-drip-coffee)
    (john . medium-latte)))

;; retrieve a value with assoc
(assoc 'lisa *drink-order*)

;; push will add a new entry, which will get returned first as it's in front of the existing one
(push '(lisa . large-mocha-with-whipped-cream) *drink-order*)
(assoc 'lisa *drink-order*)


;; tree-like data
(defparameter *house*
  '((walls (mortar (cement) (water) (sand)) (bricks))
    (windows (glass) (frame) (curtains))
    (roof (shingles) (chimney))))
