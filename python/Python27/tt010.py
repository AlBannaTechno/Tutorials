from Tkinter import * 	# (1)

root = Tk()				# (2)
root.mainloop()			# (3)

"""
Explanation:
(1) The first statement imports Tkinter, so that it is available for use. Note that the form of the import
("from Tkinter import *") means that we will not have to qualify anything that we get from Tkinter with
a "Tkinter." prefix.

(2) The second statement creates a "toplevel" window. Technically, what the the second statement is
doing, is creating an instance of the class "Tkinter.Tk".

This toplevel window is the highest-level GUI component in any Tkinter application. By convention, the
toplevel window is usually named "root".

(3) The third statement executes the "mainloop" (that is, the event loop) method of the "root" object.
As the mainloop runs, it waits for events to happen in root. If an event occurs, then it is handled and
the loop continues running, waiting for the next event. The loop continues to execute until a "destroy"
event happens to the root window. A "destroy" event is one that closes a window. When the root is
destroyed, the window is closed and the event loop is exited.
"""