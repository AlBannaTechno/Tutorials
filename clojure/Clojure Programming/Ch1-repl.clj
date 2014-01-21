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
   ;; 2.592e9 -> one month in ms
   :exp-date (java.util.Date. (long (+ 2.592e9 (.getTime join-date))))})
(make-user "Bobby")
(make-user "Bobby"
           :join-date (java.util.Date. 111 0 1)
           :email "bobby@example.com")

(fn [x y] (Math/pow x y))
;; can be defined as
#(Math/pow %1 %2)