#lang racket
(require algorithms)

(define (value c)
  (cond
    [(char=? c #\() 1]
    [(char=? c #\)) -1]
    [else 0]))

(define (nesting expr)
  (argmax identity (scanl + (map value (string->list expr)))))

(define (main)
  (for ([i '("3 + 4" "(3 + 4)" "((()))" "((3*4) + 4)")])
    (printf "nesting of ~s is ~a~n" i (nesting i))))

(main)