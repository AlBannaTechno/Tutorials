#lang racket

(require
 2htdp/image
 2htdp/universe)


;; -- Data Structures --
;; The orc world
(struct orc-world (player lom num-attacks target) #:mutable #:transparent)

;; The player
(struct player (health agility strength) #:mutable #:transparent)

;; Monsters
(struct monster (image [health #:mutable]) #:transparent)

(struct orc monster (club) #:transparent)
(struct hydra monster () #:transparent)
(struct slime monster (sliminess) #:transparent)
(struct brigand monster () #:transparent)


;; -- Constants --
;; Player attributes
(define +max-health+ 35)
(define +max-agility+ 35)
(define +max-strength+ 35)

;; Attack and damage
(define +num-attacks+ 4)
(define +stab-damage+ 2)
(define +flail-damage+ 3)
(define +healing+ 8)

;; Monster attributes
(define +num-monsters+ 12)
(define +per-row+ 4)
(unless (zero? (remainder +num-monsters+ +per-row+))
  (error 'constraint "+per-row+ must divide +num-monsters+ evenly into rows"))

(define +monster-health+ 9)
(define +club-strength+ 8)
(define +sliminess+ 5)

(define +health-damage+ -2)
(define +agility-damage+ -3)
(define +strength-damage+ -4)

;; String constants
(define +strength+ "strength")
(define +agility+ "agility")
(define +health+ "health")
(define +lose+ "You lose")
(define +win+ "You win")
(define +dead+ "Dead")
(define +remaining+ "Remaining attacks ")
(define +instructions-2+ "Select a monster using the arrow keys")
(define +instructions-1+ "Press S to Stab a monster | Press F to Flail wildly | Press H to Heal")

;; Graphical constants
(define +health-bar-height+ 12)
(define +health-bar-width+ 50)

;; Compute constants for image frames
(define +orc+     (bitmap "graphics/orc.png"))
(define +hydra+   (bitmap "graphics/hydra.png"))
(define +slime+   (bitmap "graphics/slime.bmp"))
(define +brigand+ (bitmap "graphics/brigand.bmp"))

(define +pic-list+ (list +orc+ +hydra+ +slime+ +brigand+))
(define w (apply max (map image-width +pic-list+)))
(define h (apply max (map image-height +pic-list+)))

;; Images: player, monsters and constant texts
(define +player-image+ (bitmap "graphics/player.bmp"))

(define +frame+ (rectangle w h 'outline 'white))
(define +target+ (circle (- (/ w 2) 2) 'outline 'blue))

(define +orc-image+     (overlay +orc+ +frame+))
(define +hydra-image+   (overlay +hydra+ +frame+))
(define +slime-image+   (overlay +slime+ +frame+))
(define +brigand-image+ (overlay +brigand+ +frame+))

(define +v-spacer+ (rectangle 0 10 "solid" "white"))
(define +h-spacer+ (rectangle 10 0 "solid" "white"))

;; Fonts, texts and colors
(define +agility-color+ "blue")
(define +health-color+ "crimson")
(define +strength-color+ "forest green")
(define +monster-color+ "crimson")
(define +message-color+ "black")
(define +attack-color+ "crimson")

(define +health-size+ (- +health-bar-height+ 4))
(define +dead-text-size+ (- +health-bar-height+ 2))
(define +instruction-text-size+ 16)
(define +messages-size+ 40)

(define +instruction-text+
  (above (text +instructions-2+ (- +instruction-text-size+ 2) "blue")
         (text +instructions-1+ (- +instruction-text-size+ 4) "blue")))

(define +dead-text+ (text +dead+ +dead-text-size+ "crimson"))


;; -- Main --
;; Start
(define (start-game)
  (big-bang (initialize-orc-world)
            (on-key player-acts-on-monsters)
            (to-draw render-orc-battle)
            (stop-when end-of-orc-battle? render-the-end)))

;; Create the orc world
(define (initialize-orc-world)
  (define player0 (initialize-player))
  (define lom0 (initialize-monsters))
  (orc-world player0 lom0 (random-number-of-attacks player0) 0))

;; Act on key events by the player
(define (player-acts-on-monsters w k)
  (cond [(zero? (orc-world-num-attacks w)) w]
        
        [(key=? "s" k) (stab w)]
        [(key=? "f" k) (flail w)]
        [(key=? "h" k) (heal w)]

        [(key=? "up" k)    (move-target w (- +per-row+))]
        [(key=? "down" k)  (move-target w (+ +per-row+))]
        [(key=? "left" k)  (move-target w -1)]
        [(key=? "right" k) (move-target w +1)]

        [(key=? "e" k) (end-turn w)]
        [(key=? "n" k) (initialize-orc-world)]

        [else w])
  (give-monster-turn-if-num-attacks=0 w)
  w)

;; Renders the orc world
(define (render-orc-battle w)
  (render-orc-world w (orc-world-target w) (instructions w)))

;; Check if the battle is over; if the player is dead or all monsters are dead
(define (end-of-orc-battle? w)
  (or (win? w) (lose? w)))

;; Render the final orc world
(define (render-the-end w)
  (render-orc-world w #f (message (if (lose? w) +lose+ +win+))))


;; -- Initializers --
;; Create a player
(define (initialize-player)
  (player +max-health+ +max-agility+ +max-strength+))

;; Create a list of random monsters
(define (initialize-monsters)
  ;; Makes a random monster
  (define (create-monster _)
    (define health (random+ +monster-health+))
    (case (random 4)
      [(0) (orc +orc-image+ health (random+ +club-strength+))]
      [(1) (hydra +hydra-image+ health)]
      [(2) (slime +slime-image+ health (random+ +sliminess+))]
      [(3) (brigand +brigand-image+ health)]
      [else (error "Can't happen")]))
  (build-list +num-monsters+ create-monster))

;; Compute a feasible number of attacks the player may execute
(define (random-number-of-attacks p)
  (random-quotient (player-agility p) +num-attacks+))


;; -- Key Events --
;; Move the currently selected target
(define (move-target w n)
  (set-orc-world-target! w (modulo (+ n (orc-world-target w)) +num-monsters+)))

;; End the players turn forcably
(define (end-turn w)
  (set-orc-world-num-attacks! w 0))

;; Stab the targetted monster
(define (stab w)
  (decrease-num-attacks w)
  (define target (current-target w))
  (define damage
    (random-quotient (player-strength (orc-world-player w)) +stab-damage+))
  (damage-monster target damage))

;; Flail around and hit a random number of monsters
(define (flail w)
  (decrease-num-attacks w)
  (define target (current-target w))
  (define alive (filter monster-alive? (orc-world-lom w)))
  (define num-pick
    (min (random-quotient (player-strength (orc-world-player w)) +flail-damage+)
         (length alive)))
  (define getem (cons target (take alive num-pick)))
  (for-each (lambda (m) (damage-monster m 1)) getem))

;; Heal the player
(define (heal w)
  (decrease-num-attacks w)
  (player-health+ (orc-world-player w) +healing+))

;; Decrease the number of remaining attacks
(define (decrease-num-attacks w)
  (set-orc-world-num-attacks! w (sub1 (orc-world-num-attacks w))))

;; Reduce the health points of a monster
(define (damage-monster m dx)
  (set-monster-health! m (interval- (monster-health m) dx)))

;; Get the currently targetted monster
(define (current-target w)
  (list-ref (orc-world-lom w) (orc-world-target w)))


;; -- Monster Actions --
;; Attack the player if it is the monsters turn
(define (give-monster-turn-if-num-attacks=0 w)
  (when (zero? (orc-world-num-attacks w))
    (define player (orc-world-player w))
    (all-monsters-attack-player player (orc-world-lom w))
    (set-orc-world-num-attacks! w (random-number-of-attacks player))))

;; Each monster attacks the player
(define (all-monsters-attack-player player lom)
  (define (one-monster-attacks-player m)
    (cond [(orc? m)
           (player-health+ player (random- (orc-club m)))]
          [(hydra? m)
           (player-health+ player (random- (monster-health m)))]
          [(slime? m)
           (player-agility+ player (random- (slime-sliminess m)))]
          [(brigand? m)
           (case (random 3)
             [(0) (player-health+ player +health-damage+)]
             [(1) (player-agility+ player +agility-damage+)]
             [(2) (player-strength+ player +strength-damage+)])]))
  (for-each one-monster-attacks-player (filter monster-alive? lom)))


;; -- Player Manipulation --
;; Change the players selector attribute by the given delta, but max out
(define (player-update! setter selector max)
  (lambda (player dx)
    (setter player (interval+ (selector player) dx max))))

;; Player health addition
(define player-health+
  (player-update! set-player-health! player-health +max-health+))

;; Player agility addition
(define player-agility+
  (player-update! set-player-agility! player-agility +max-agility+))

;; Player strength addition
(define player-strength+
  (player-update! set-player-strength! player-strength +max-strength+))


;; -- Rendering --
;; Draws all the monsters and the player, then adds the message
(define (render-orc-world w target text)
  (define i-player  (render-player (orc-world-player w)))
  (define i-monster (render-monsters (orc-world-lom w) target))
  (above +v-spacer+
         (beside +h-spacer+
                 i-player
                 +h-spacer+ +h-spacer+ +h-spacer+
                 (above i-monster
                        +v-spacer+ +v-spacer+ +v-spacer+
                        text)
                 +h-spacer+)
         +v-spacer+))

;; Render the player with three status bars
(define (render-player p)
  (above/align "left"
               (status-bar (player-strength p) +max-strength+ +strength-color+ +strength+)
               +v-spacer+
               (status-bar (player-agility p) +max-agility+ +agility-color+ +agility+)
               +v-spacer+
               (status-bar (player-health p) +max-health+ +health-color+ +health+)
               +v-spacer+ +v-spacer+ +v-spacer+
               +player-image+))

;; Creates a labeled rectangle of width/max proportions
(define (status-bar v-current v-max color label)
  (define w (max (* (/ v-current v-max) +health-bar-width+) 0))
  (define f (rectangle w +health-bar-height+ 'solid color))
  (define b (rectangle +health-bar-width+ +health-bar-height+ 'outline color))
  (define bar (overlay/align 'left 'top f b))
  (beside bar +h-spacer+ (text label +health-size+ color)))

;; Create a message image
(define (message str)
  (text str +messages-size+ +message-color+))

;; Create an instructions image
(define (instructions w)
  (define na (number->string (orc-world-num-attacks w)))
  (define ra (string-append +remaining+ na))
  (above (text ra +instruction-text-size+ +attack-color+) +instruction-text+))

;; Add all monsters, their status bars and the current target
(define (render-monsters lom with-target)
  ;; The currently targetted monster
  (define target
    (if (number? with-target)
        (list-ref lom with-target)
        'random-error-symbol))
  ;; Render one monster to an image
  (define (render-one-monster m)
    (define image
      (if (eq? m target)
          (overlay +target+ (monster-image m))
          (monster-image m)))
    (define health (monster-health m))
    (define health-bar
      (if (< health 1)
          (overlay +dead-text+ (status-bar 0 1 'white ""))
          (status-bar health +monster-health+ +monster-color+ "")))
    (above health-bar image))
  (arrange (map render-one-monster lom)))

;; Break a list of images into rows of +per-row+
(define (arrange lom)
  (cond [(empty? lom) empty-image]
        [else (define row-image (apply beside (take lom +per-row+)))
              (above row-image (arrange (drop lom +per-row+)))]))


;; -- End Conditions --
;; Check if the player won
(define (win? w)
  (all-dead? (orc-world-lom w)))

;; Check if the player lost
(define (lose? w)
  (player-dead? (orc-world-player w)))

;; Check if the player is dead
(define (player-dead? p)
  (or (< (player-health p) 1)
      (< (player-agility p) 1)
      (< (player-strength p) 1)))

;; Check if all the monsters in the list are dead
(define (all-dead? lom)
  (not (ormap monster-alive? lom)))

;; Check if the monster is alive
(define (monster-alive? m)
  (> (monster-health m) 0))


;; -- Utility Functions --
;; Generate a random number between 1 and the (quotient x y)
(define (random-quotient x y)
  (define div (quotient x y))
  (if (> 0 div) 0 (random+ (add1 div))))

;; Generate a random number in [1, n]
(define (random+ n)
  (add1 (random n)))

;; Generates a random number in [-n, -1]
(define (random- n)
  (- (add1 (random n))))

;; Subtract n from val but stay in [0, max-value]
(define (interval- val n (max-value 100))
  (min (max (- val n)) max-value))

;; Add n to val but stay in [0, max-value]
(define (interval+ val n (max-value 100))
  (interval- val (- n) max-value))