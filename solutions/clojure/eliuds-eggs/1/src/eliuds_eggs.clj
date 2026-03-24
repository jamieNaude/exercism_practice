(ns eliuds-eggs)

(defn brian-kernighan [num count]
  (if (zero? num)
    count
    (recur (bit-and num (dec num)) (inc count))))

(defn egg-count [num]
  (brian-kernighan num 0))
