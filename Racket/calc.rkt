#lang racket

(define MAX 999)
(define MIN -999)

(define (add f s)
  (cond [(not (integer? f)) (error "Parsing Error")]
        [(not (integer? s)) (error "Parsing Error")]
        [(> (+ f s) MAX) (error "Overflow Error")]
        [(< (+ f s) MIN) (error "Overflow Error")]
        [else (+ f s)]))
(define (sub f s)
  (cond [(not (integer? f)) (error "Parsing Error")]
        [(not (integer? s)) (error "Parsing Error")]
        [(> (- f s) MAX) (error "Overflow Error")]
        [(< (- f s) MIN) (error "Overflow Error")]
        [else (- f s)]))
(define (mul f s)
  (cond [(not (integer? f)) (error "Parsing Error")]
        [(not (integer? s)) (error "Parsing Error")]
        [(> (* f s) MAX) (error "Overflow Error")]
        [(< (* f s) MIN) (error "Overflow Error")]
        [else (* f s)]))
(define (div f s)
  (cond [(not (integer? f)) (error "Parsing Error")]
        [(not (integer? s)) (error "Parsing Error")]
        [(> (/ f s) MAX) (error "Overflow Error")]
        [(< (/ f s) MIN) (error "Overflow Error")]
        [else (/ f s)]))
(define (mod f s)
  (cond [(not (integer? f)) (error "Parsing Error")]
        [(not (integer? s)) (error "Parsing Error")]
        [(> (remainder f s) MAX) (error "Overflow Error")]
        [(< (remainder f s) MIN) (error "Overflow Error")]
        [else (remainder f s)]))
(define (exp f s)
  (cond [(not (integer? f)) (error "Parsing Error")]
        [(not (integer? s)) (error "Parsing Error")]
        [(> (expt f s) MAX) (error "Overflow Error")]
        [(< (expt f s) MIN) (error "Overflow Error")]
        [else (expt f s)]))
(define (srt f)
  (cond [(not (integer? f)) (error "Parsing Error")]
        [(> (sqrt f) MAX) (error "Overflow Error")]
        [(< (sqrt f) MIN) (error "Overflow Error")]
        [else (sqrt f)]))

"Enter an equation."
