(defn average
  [numbers]
  (/ (apply + numbers) (count numbers)))
(average [1 2 3 4 5])

(let [a (inc (rand-int 6))
      b (inc (rand-int 6))]
  (println (format "You rolled a %s and a %s" a b))
  (+ a b))

(defn hypot
  [x y]
  (let [x2 (* x x)
        y2 (* y y)]
    (Math/sqrt (+ x2 y2))))
(hypot 8 12)

(def v [42 "foo" 99.2 [5 12]])
(first v)
(second v)
(last v)
(nth v 2)
(v 2)
(.get v 2)

(+ (first v) (v 2))
(+ (first v) (first (last v)))

(let [[x y z] v]
  (+ x z))
;; The above is the same as
(let [x (nth v 0)
      y (nth v 1)
      z (nth v 2)]
  (+ x z))

(let [[x _ _ [y z]] v]
  (+ x y z))

(let [[x & rest] v]
  rest)
(let [[x _ z :as original-vector] v]
  (conj original-vector (+ x z)))

(def m {:a 5 :b 6
        :c [7 8 9]
        :d {:e 10 :f 11}
        "foo" 88
        42 false})

(let [{a :a b :b} m]
  (+ a b))

(let [{f "foo"} m]
  (+ f 12))

(let [{v 42} m]
  (if v 1 0))

(let [{x 3 y 8} [12 0 0 -19 44 6 0 0 1]]
  (+ x y))

(let [{{e :e} :d} m]
  (* 2 e))

(let [{[x _ y] :c} m]
  (+ x y))

(def map-in-vector ["James" {:birthday (java.util.Date. 74 1 6)}])
(let [[name {bd :birthday}] map-in-vector]
  (str name " was born on " bd))

(let [{r1 :x r2 :y :as randoms}
      (zipmap [:x :y :z] (repeatedly (partial rand-int 10)))]
  (assoc randoms :sum (+ r1 r2)))

(let [{k :unknown x :a
       :or {k 50}} m]
  (+ k x))
;; above is better than the alternative
(let [{k :unkown x :a} m
      k (or k 50)]
  (+ k x))
;; :or knows the difference between false and nil
(let [{opt1 :option} {:option false}
      opt1 (or opt1 true)
      {opt2 :option :or {opt2 true}} {:option false}]
  {:opt1 opt1 :opt2 opt2})

(def chas {:name "Chas" :age 31 :location "Massaschusetts"})
(let [{name :name age :age location :location} chas]
  (format "%s is %s years old and lives in %s." name age location))
;; an easier way to do the above
(let [{:keys [name age location]} chas]
  (format "%s is %s years old and lives in %s." name age location))

(def brian {"name" "Brian" "age" 31 "location" "British Columbia"})
(let [{:strs [name age location]} brian]
  (format "%s is %s years old and lives in %s." name age location))

(def christophe {'name "Christophe" 'age 33 'location "Rhone-Alpes"})
(let [{:syms [name age location]} christophe]
  (format "%s is %s years old and lives in %s." name age location))

(def user-info ["robert8990" 2011 :name "Bob" :city "Boston"])
(let [[username account-year & extra-info] user-info
      {:keys [name city]} (apply hash-map extra-info)]
  (format "%s is in %s" name city))
;; Above is tolerable, below uses lets destructuring forms map destructuring of rest seqs
(let [[username account-year & {:keys [name city]}] user-info]
  (format "%s is in %s" name city))

(fn [x]
  (+ 10 x))

((fn [x] (+ 10 x)) 8)
;; is equivalent to
(let [x 8]
  (+ 10 x))

((fn [x y z] (+ x y z))
 3 4 12)
;; is the same as
(let [x 3
      y 4
      z 12]
  (+ x y z))

(def strange-adder (fn adder-self-reference
                     ([x] (adder-self-reference x 1))
                     ([x y] (+ x y))))
(strange-adder 10)
(strange-adder 10 50)

(letfn [(odd? [n]
          (even? (dec n)))
        (even? [n]
          (or (zero? n)
              (odd? (dec n))))])
(odd? 11)

;; The strange adder above can also be defined as so
(defn strange-adder
  ([x] (strange-adder x 1))
  ([x y] (+ x y)))

(def redundant-adder (fn redundant-adder
                       [x y z]
                       (+ x y z)))
;; can be done as
(defn redundant-adder
  [x y z]
  (+ x y z))

(defn concat-rest
  [x & rest]
  (apply str (butlast rest)))
(concat-rest 0 1 2 3 4)

(defn make-user
  [& [user-id]]
  {:user-id (or user-id (str (java.util.UUID/randomUUID)))})
(make-user)
(make-user "Bobby")

(defn make-user
  [username & {:keys [email join-date]
               :or {join-date (java.util.Date.)}}]
  {:username username
   :join-date join-date
   :email email
   :exp-date (java.util.Date. (long (+ 2.592e9 (.getTime join-date))))})

(make-user "Bobby")
(make-user "Bobby"
           :join-date (java.util.Date. 111 0 1)
           :email "bobby@example.com")

(fn [x y] (Math/pow x y))
;; can be written as an anonymous function
#(Math/pow %1 %2)

(read-string "#(Math/pow %1 %2)")

(fn [x y]
  (println (str x \^ y))
  (Math/pow x y))
;; anonymous functions don't wrap themselves in an implicit do form, so the above would be
(#(do (println (str %1 \^ %2))
      (Math/pow %1 %2)) 2 3)

(fn [x & rest]
  (- x (apply - rest)))
;; function literals can also take 'the rest' of variables given to it, by using %&
(#(- % (apply + %&)) 1 2 3 4 5)

(fn [x]
  (fn [y]
    (+ x y)))
;; Although the above is acceptable, this won't work as an anonymous function
;;#(#(+ % %))

;; logical truth is anything other than false or nil
(if "hi" \t)
(if 42 \t)
(if nil "unevaluated" \f)
(if false "unevaluated" \f)
(if (not true) \t)

;; Clojure provides true? and false? predicates, but these ONLY check for boolean values
(true? "string")
(if "string" \t \f)

(loop [x 5]
  (if (neg? x)
    x
    (recur (dec x))))

(defn countdown
  [x]
  (if (zero? x)
    :BLASTOFF!
    (do (println x)
      (recur (dec x)))))
(countdown 5)

(def x 5)
x
(var x)
#'x

;; Java interlop following, the equivalent in Java, sugared Clojure and special form version
;; new java.util.ArrayList(100)
(java.util.ArrayList. 100)
(new java.util.ArrayList 100)

;;Math.pow(2, 10)
(Math/pow 2 10)
(. Math pow 2 10)

;; "Hello".substring(1, 3)
(.substring "Hello" 1 3)
(. "Hello" substring 1 3)

;; Integer.MAX_VALUE
Integer/MAX_VALUE
(. Integer MAX_VALUE)

;; someObject.someField
(.someField some-object)
(. some-object some-field)

(defn average
  [numbers]
  (/ (apply + numbers) (count numbers)))
;; is equivalent to
(def average (fn average
               [numbers]
               (/ (apply + numbers) (count numbers))))

;; A simple, naive reimplementation of Clojure's REPL
(defn embedded-repl
  "A naive Clojure REPL implementation. Enter ':quit' to exit."
  []
  (print (str (ns-name *ns*) ">>> "))
  (flush)
  (let [expr (read)
        value (eval expr)]
    (when (not= :quit value)
      (println value)
      (recur))))
