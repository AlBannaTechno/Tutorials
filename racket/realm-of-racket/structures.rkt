#lang racket
(struct student (name id# dorm) #:transparent)

(define freshman1 (student 'Joe 1234 'NewHall))

;>(student-name freshman1)
;>(student-id# freshman1)

(define mimi (student 'Mimi 1234 'NewHall))
(define nicole (student 'Nicole 5678 'NewHall))
(define rose (student 'Rose 8765 'NewHall))
(define eric (student 'Eric 4321 'NewHall))
(define in-class (list mimi nicole rose eric))

;>(student-id# (third in-class))

(struct student-body (freshmen sophomores juniors seniors) #:transparent)

(define all-students
  (student-body (list freshman1 (student 'Mary 0101 'OldHall))
                (list (student 'Jeff 5678 'OldHall))
                (list (student 'Bob 4321 'Apartment))
                empty))

;>(student-name (first (student-body-freshmen all-students)))
;>(student-name (second (student-body-freshmen all-students)))
;>(student-name (first (student-body-juniors all-students)))
;>all-students

(define sophomore3 (student 'David 100234 'PG))

;>(student-name sophomore3)
;>(student? 'a)
;>(student? sophomore3)
;>(student? (student 1 2 3))
;>(student? "I am a student")

(struct point (x y) #:transparent)

(define (distance-to-origin p)
  (sqrt (+ (sqr (point-x p)) (sqr (point-y p)))))

;>(distance-to-origin (point 3 4))

(define pt1 (point -1 2))
(define pt2 (point -1 2))

;>(equal? pt1 pt2)
;>the above will be false if the struct is not created #:transparent
;>(eq? pt1 pt2)
;>(eq? pt1 pt1)

(define pt3 pt1)

;>(eq? pt1 pt3)

(define (eq-first-items list1 list2)
  (eq? (first list1) (first list2)))

;>(eq-first-items (cons pt1 empty) (cons pt3 empty))
;>(eq-first-items (cons pt1 empty) (cons pt2 empty))


