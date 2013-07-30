#----- task 2:  define the event handler routines ---------------------
def handle_A():
	print "Wrong! Try again!"

def handle_B():
	print "Absolutely right! Trillium is a kind of flower!"

def handle_C():
	print "Wrong! Try again!"

# ------------ task 1: define the appearance of the screen ------------
print "\n"*100 # clear the screen
print "VERY CHALLENGING GUESSING GAME"
print "========================================================"
print "Press the letter of your answer, then the ENTER key."
print
print "A. Animal"
print "B. Vegetable"
print "C. Mineral"
print
print "X. Exit from this program"
print
print "========================================================"
print "What kind of thing is 'Trillium'?"
print

# ---- task 4: the event loop. We loop forever, observing events. ---

while True:
	
	# We observe the next event
	answer = raw_input().upper()
	
	# -------------------------------------------------------
	# Task 3: Associate interesting keyboard events with their
	# event handlers. A simple form of binding.
	# -------------------------------------------------------
	if answer == "A": handle_A()
	if answer == "B": handle_B()
	if answer == "C": handle_C()
	if answer == "X":
		# clear the screen and exit the event loop
		print "\n"*100
		break
		
	# Note that any other events are uninteresting, and are ignored