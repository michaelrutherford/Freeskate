(defun input-parser (to-be-parsed)
  (if (and (numberp to-be-parsed) (not (floatp to-be-parsed)))
      (progn (format t "Decimal     => ~d~%" to-be-parsed)
	     (format t "Binary      => ~B~%" to-be-parsed)
             (format t "Hexadecimal => ~X~%" to-be-parsed)
	     (format t "Octal       => ~O~%" to-be-parsed))
      (format t "Invalid input")))

(defun usr-input ()
  (let ((inp (read)))
    (input-parser inp)))

(usr-input)
