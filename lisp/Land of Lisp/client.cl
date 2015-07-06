(require 'usocket)


(defparameter my-stream (usocket:socket-stream (usocket:socket-connect #(127 0 0 1) 4321)))

;; Write to the server and force the buffer onto the stream
(print "Yo! Server!" my-stream)
(force-output my-stream)

;; Read from the server
(read my-stream)

;; And done
(close my-stream)
