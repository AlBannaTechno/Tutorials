from Tkinter import *

class MyApp:
	def __init__(self, parent):
		self.myParent = parent 		# (7) remember my parent, the root
		self.myContainer1 = Frame(parent)
		self.myContainer1.pack()

		self.button1 = Button(self.myContainer1)
		self.button1.configure(text="OK", background="green")
		self.button1.pack(side=LEFT)
		self.button1.bind("<Button-1>", self.button1Click)	# (1)

		self.button2 = Button(self.myContainer1)
		self.button2.configure(text="Cancel", background="red")
		self.button2.pack(side=RIGHT)
		self.button2.bind("<Button-1>", self.button2Click)	# (2)

	def button1Click(self, event):					# (3)
		if self.button1["background"] == "green":	# (4)
			self.button1["background"] = "yellow"
		else:
			self.button1["background"] = "green"
		
	def button2Click(self, event):		# (5)
		self.myParent.destroy()			# (6)

root = Tk()
myapp = MyApp(root)
root.mainloop()

"""
Explanation:
(1) We bind "<Button-1>" events (clicks of the left mouse button) on the button1 widget to the
"self.button1Click" method. When button1 is left-clicked with the mouse, the self.button1Click() method
will be invoked to handle the event.

(3) Note that, although they aren't specified on the "bind" operation, self.button1Click() will be passed
two arguments. The first, of course, will be "self", which is always the first argument to all class
methods in Python. The second will be an event object. This technique of binding and event (that is,
using the bind() method) always implicitly passes an event object as an argument.

In Python/Tkinter, when an event occurs, it takes the form of an event object. An event object is
extremely useful, because it carries with it all sorts of useful information and methods. You can examine
the event object to find out what kind of event occurred, the widget where it occurred, and other useful
bits of information.

(4) So, what do we want to happen when button1 is clicked? Well, in this case we have it do something
quite simple. It simply changes its color from green to yellow, and back again.

(2) Let's make button2 (the "Goodbye!" button) actually do some useful work. We will make it shut
down the window. So we bind a left-mouse click in button2 to the button2Click() method, and

(6) We have the button2Click() method destroy the root window, the parent window of myapp. This will
have a ripple effect, and will destroy all the children and descendent's of the root. In short, every part
of the GUI will be destroyed.

Of course, to do this, myapp has to know who its parent is. So (7) we add code to its constructor to
allow myapp to remember its parent.
"""