(defparameter *noun* '(wizard     afro
                       plant      sequence
                       alien      diameter
                       tree       squid
                       coconut    radio
                       skull      vector
                       history    planet
                       hamburger  chair
                       stone      grape
                       goose      matrix
                       goldfish   ninja
                       cabin      octopus
                       kneecap    valley
                       flower     camera
                       cereal     agent
                       slumber    ocean
                       gorilla    soldier
                       viking     leaf
                       mongoose   punch
                       mountain   science
                       warrior    granola
                       falcon     trashcan
                       rock       knight
                       particle   terrace))
(defparameter *adjv* '(flaming    blue
                       flying     cold
                       sad        red
                       benevolent genetic
                       hyper      hateful
                       outer      orange
                       clueless   fast
                       angelic    aquatic
                       yellow     scientific
                       foreign    inner
                       crazy      pink
                       patriotic  invisible
                       black      oceanic
                       tall       green
                       psycho     sneaky
                       biological confused
                       malevolent magic
                       sick       purple
                       psychic    majestic
                       evil       smokey))
(defparameter *verb* '(punch    jump
                       fly      bend
                       swing    consume
                       destroy  swim
                       run      throw
                       break    drive
                       rise     dodge
                       collapse lean
                       awaken   sprint
                       crush    climb
                       fall     miss
                       freeze   create
                       remember burn))
(defparameter form (rnd-gen))
(defun rnd-gen ()
  (random 7))
(defun gen ()
  (setq form (rnd-gen))
  (cond ((eq form 0) (list (elt *adjv* (random (length *adjv*)))
                           (elt *noun* (random (length *noun*)))))
        ((eq form 1) (list (elt *noun* (random (length *noun*))) 
                           (elt *noun* (random (length *noun*)))))
        ((eq form 2) (list (elt *noun* (random (length *noun*))) 
                           (elt *verb* (random (length *verb*)))))
        ((eq form 3) (list (elt *verb* (random (length *verb*)))
			   (elt *noun* (random (length *noun*)))))
        ((eq form 4) (list 'the 
                           (elt *noun* (random (length *noun*)))))
        ((eq form 5) (list 'the 
                           (elt *adjv* (random (length *adjv*)))
                           (random 100)))
        ((eq form 6) (list (elt *noun* (random (length *noun*))) 
                           (random 100)))))
