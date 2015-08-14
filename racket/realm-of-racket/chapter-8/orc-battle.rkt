#lang racket

(require
 2htdp/image
 2htdp/universe)


;; Data structures
;; The world
(struct orc-world (player lom attack#) #:transparent)

;; The player
(struct player (health agility strength) #:transparent)

(define MAX-HEALTH 35)
(define MAX-AGILITY 35)
(define MAX-STRENGTH 35)

;; Monsters
(struct monster ([health #:mutable]) #:transparent)

(struct orc monster (club) #:transparent)
(struct hydra monster () #:transparent)
(struct slime monster (sliminess) #:transparent)
(struct brigand monster ())


(define (stab-orc.v1 an-orc)
  (orc (- (monster-health an-orc) DAMAGE) (orc-club an-orc)))

(define (stab-orc.v2 an-orc)
  (set-monster-health! an-orc (- (monster-health an-orc) DAMAGE)))
