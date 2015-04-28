(if (= (+ 1 2) 3)
    'yup
    'nope)

(if (= (+ 1 2) 4)
    'yup
    'nope)

(if '(1)
    'stuff
    'none)

(if '()
    'stuff
    'none)

;; Anything empty is false, otherwise true
;; '() () 'nil nil are the only false values

(if (oddp 5)
    'odd
    'even)

(if (oddp 5)
    'odd
    (/ 1 0)) ; will never evaluate


(defvar *number-was-odd* nil)

(if (oddp 5)
    (progn (setf *number-was-odd* t)
           'odd-number)
    'even-number)

*number-was-odd*

(defvar *number-is-odd* nil)

;; when true
(when (oddp 5)
  (setf *number-is-odd* t)
  'odd-number)

*number-is-odd*

;; unless true
(unless (oddp 4)
  (setf *number-is-odd* nil)
  'even-number)

*number-is-odd*

;; Cond!

(defvar *arch-enemy* nil)

(defun pudding-eater (person)
  (cond ((eq person 'henry) (setf *arch-enemy* 'stupid-lisp-alien)
         '(curse you lisp alien - you ate my pudding))
        ((eq person 'johnny) (setf *arch-enemy* 'useless-old-johnny)
         '(i hope you choked on my putting johnny))
        (t
         '(why you eat my pudding stranger ?))))

(pudding-eater 'johnny)
*arch-enemy*
(pudding-eater 'george-cloony)
*arch-ememy

;; The above as case
(defun pudding-eater (person)
  (case person
    ((henry) (setf *arch-enemy* 'stupid-lisp-alien)
     '(curse you lisp alien - you ate my pudding))
    ((johnny) (setf *arch-enemy* 'useless-old-johnny)
     '(i hope you choked on my pudding johnny))
    (otherwise
     '(why you eat my pudding stranger ?))))

;; Stealth conditionals ! "and" and "or"!

(and (oddp 5) (oddp 7) (oddp 9))
(or (oddp 4) (oddp 7) (oddp 8))

(defparameter *is-it-even* nil)

;; false evaluates the next statement
(or (oddp 4) (setf *is-it-even* t))
*is-it-even*

;; true shortcuts and skips the next statement
(or (oddp 5) (setf *is-it-even* t))
*is-it-even*
