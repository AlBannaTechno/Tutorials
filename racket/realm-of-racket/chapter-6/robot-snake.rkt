#lang racket

(require
 2htdp/image
 2htdp/universe)


;; Data Structures
(struct pit (snake goos) #:transparent)
(struct snake (dir segs) #:transparent)
(struct goo (loc expire) #:transparent)
(struct posn (x y) #:transparent)


;; Constants
;; Tick Rate
(define TICK-RATE 1/10)

;; Board size
(define SIZE 30)

;; Snake size
(define SEG-SIZE 15)

;; Goo
(define MAX-GOO 5)
(define EXPIRATION-TIME 150)

;; Graphical board
(define WIDTH-PX (* SEG-SIZE 30))
(define HEIGHT-PX (* SEG-SIZE 30))

;; Visual
(define MT-SCENE (empty-scene WIDTH-PX HEIGHT-PX))
(define GOO-IMG (bitmap "graphics/goo.gif"))
(define SEG-IMG (bitmap "graphics/body.gif"))
(define HEAD-IMG (bitmap "graphics/head.gif"))

(define HEAD-LEFT-IMG HEAD-IMG)
(define HEAD-DOWN-IMG (rotate 90 HEAD-LEFT-IMG))
(define HEAD-RIGHT-IMG (flip-horizontal HEAD-LEFT-IMG))
(define HEAD-UP-IMG (flip-vertical HEAD-DOWN-IMG))

(define ENDGAME-TEXT-SIZE 15)


;; Main
;; Start the game
(define (start-snake)
  (big-bang
   (pit (snake "right" (list (posn 1 1)))
        (list (fresh-goo)
              (fresh-goo)
              (fresh-goo)
              (fresh-goo)
              (fresh-goo)
              (fresh-goo)))
   (on-tick next-pit TICK-RATE)
   (on-key direct-snake)
   (to-draw render-pit)
   (stop-when dead? render-end)))

;; Take one step, eat or slither
(define (next-pit w)
  (define snake (pit-snake w))
  (define goos (pit-goos w))
  (define goo-to-eat (can-eat snake goos))
  (if goo-to-eat
      (pit (grow snake) (age-goo (eat goos goo-to-eat)))
      (pit (slither snake) (age-goo goos))))

;; Handle a key event
(define (direct-snake w ke)
  (cond [(dir? ke) (world-change-dir w ke)]
        [else w]))

;; Render the world as a scene
(define (render-pit w)
  (snake+scene (pit-snake w)
               (goo-list+scene (pit-goos w) MT-SCENE)))

;; Is the snake dead?
(define (dead? w)
  (define snake (pit-snake w))
  (or (self-colliding? snake) (wall-colliding? snake)))

;; Produces a game over image
(define (render-end w)
  (overlay (text "Game Over" ENDGAME-TEXT-SIZE "black")
           (render-pit w)))

;; Clock Ticks
;; Can the snake eat any of the goos?
(define (can-eat snake goos)
  (cond [(empty? goos) #f]
        [else (if (close? (snake-head snake) (first goos))
                  (first goos)
                  (can-eat snake (rest goos)))]))

;; Eat and replenish a goo
(define (eat goos goo-to-eat)
  (cons (fresh-goo) (remove goo-to-eat goos)))

;; Is the segment close to the goo?
(define (close? s g)
  (posn=? s (goo-loc g)))

;; Grow the snake one segment
(define (grow sn)
  (snake (snake-dir sn) (cons (next-head sn) (snake-segs sn))))

;; Movement
;; Slither the snake forward one segment
(define (slither sn)
  (snake (snake-dir sn)
         (cons (next-head sn) (all-but-last (snake-segs sn)))))

;; Compute the next head position of the snake
(define (next-head sn)
  (define head (snake-head sn))
  (define dir (snake-dir sn))
  (cond [(string=? dir "up") (posn-move head 0 -1)]
        [(string=? dir "down") (posn-move head 0 1)]
        [(string=? dir "left") (posn-move head -1 0)]
        [(string=? dir "right") (posn-move head 1 0)]))

;; Move the position by dx, dy
(define (posn-move p dx dy)
  (posn (+ (posn-x p) dx)
        (+ (posn-y p) dy)))

;; Returns a list that does not contain the last element of the given list
(define (all-but-last segs)
  (cond [(empty? (rest segs)) empty]
        [else (cons (first segs)
                    (all-but-last (rest segs)))]))


;; Rotting Goo
;; Renew and rot goos
(define (age-goo goos)
  (rot (renew goos)))

;; Renew any rotten goos
(define (renew goos)
  (cond [(empty? goos) empty]
        [(rotten? (first goos))
         (cons (fresh-goo) (renew (rest goos)))]
        [else
         (cons (first goos) (renew (rest goos)))]))

;; Rot all of the goos
(define (rot goos)
  (cond [(empty? goos) empty]
        [else (cons (decay (first goos))
                    (rot (rest goos)))]))

;; Has the goo expired
(define (rotten? g)
  (zero? (goo-expire g)))

;; Decrease the expire field
(define (decay g)
  (goo (goo-loc g) (sub1 (goo-expire g))))

;; Create a random goo with fresh expiration
(define (fresh-goo)
  (goo (posn (add1 (random (sub1 SIZE)))
             (add1 (random (sub1 SIZE))))
       EXPIRATION-TIME))


;; Keys
;; Is the given value a direction
(define (dir? x)
  (or (string=? x "up")
      (string=? x "down")
      (string=? x "left")
      (string=? x "right")))

;; Change the direction (if not opposite current snake dir
(define (world-change-dir w d)
  (define the-snake (pit-snake w))
  (cond [(and (opposite-dir? (snake-dir the-snake) d)
              (cons? (rest (snake-segs the-snake))))
         (stop-with w)]
        [else
         (pit (snake-change-dir the-snake d)
              (pit-goos w))]))

;; Are d1 and d2 opposites
(define (opposite-dir? d1 d2)
  (cond [(string=? d1 "up") (string=? d2 "down")]
        [(string=? d1 "down") (string=? d2 "up")]
        [(string=? d1 "left") (string=? d2 "right")]
        [(string=? d1 "right") (string=? d2 "left")]))

;; Rendering
;; Draws the snake onto the scene
(define (snake+scene snake scene)
  (define snake-body-scene
    (img-list+scene (snake-body snake) SEG-IMG scene))
  (define dir (snake-dir snake))
  (img+scene (snake-head snake)
             (cond [(string=? "up") HEAD-UP-IMG]
                   [(string=? "down") HEAD-DOWN-IMG]
                   [(string=? "left") HEAD-LEFT-IMG]
                   [(string=? "right") HEAD-RIGHT-IMG])
             snake-body-scene))

;; Draws all of the goo to a scene
(define (goo-list+scene goos scene)
  (define (get-posns-from-goo goos)
    (cond [(empty? goos) empty]
          [else (cons (goo-loc (first goos))
                      (get-posns-from-goo (rest goos)))]))
  (img-list+scene (get-posns-from-goo goos) GOO-IMG scene))

;; Draws an image to each posn in the list
(define (img-list+scene posns img scene)
  (cond [(empty? posns) scene]
        [else (img+scene (first posns)
                         img
                         (img-list+scene (rest posns) img scene))]))

;; Draw the given image onto a scene at the posn
(define (img+scene posn img scene)
  (place-image img
               (* (posn-x posn) SEG-SIZE)
               (* (posn-y posn) SEG-SIZE)
               scene))


;; End game
;; Determine if the snake is colliding with itself
(define (self-colliding? sn)
  (cons? (member (snake-head sn) (snake-body sn))))

;; Determine if the snake is colliding with any of the walls
(define (wall-colliding? sn)
  (define x (posn-x (snake-head sn)))
  (define y (posn-y (snake-head sn)))
  (or (= 0 x) (= x SIZE)
      (= 0 y) (= y SIZE)))


;; Auxiliary functions
;; Are the two posns equal
(define (posn=? p1 p2)
  (and (= (posn-x p1) (posn-x p2))
       (= (posn-y p1) (posn-y p2))))

;; Access the head position of the snake
(define (snake-head sn)
  (first (snake-segs sn)))

;; Access the snake's body
(define (snake-body sn)
  (rest (snake-segs sn)))

;; Change the direction of the snake
(define (snake-change-dir sn d)
  (snake d (snake-segs sn)))
