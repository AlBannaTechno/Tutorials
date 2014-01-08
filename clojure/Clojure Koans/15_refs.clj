(def the-world (ref "Hello"))
(def bizarro-world (ref {}))


;; In the beginning, there was a word
(= "Hello" (deref the-world))

;; You can get the word more succinctly, but it's the same
(= "Hello" @the-world)

;; You can be the change you wish to see in the world
(= "better" (do
              (dosync (ref-set the-world "better"))
              @the-world))

;; Alter where you need not replace
(= "better!!!" (let [exclamator (fn [x] (str x "!"))]
                 (dosync
                  (alter the-world exclamator)
                  (alter the-world exclamator)
                  (alter the-world exclamator))
                 @the-world))

;; Don't forget to do your work in a transaction!
(= 0 (do (dosync (ref-set the-world 0))
       @the-world))

;; Functions passed to alter may depend on the data in the ref
(= 20 (do (dosync (alter the-world + 20))
        @the-world))

;; Two worlds are better than one
(= ["Real Jerry" "Bizzaro Jerry"]
   (do
     (dosync
      (ref-set the-world {})
      (alter the-world assoc :jerry "Real Jerry")
      (alter bizarro-world assoc :jerry "Bizzaro Jerry")
      [(:jerry @the-world) (:jerry @bizarro-world)])))
