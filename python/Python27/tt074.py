from Tkinter import *

class MyApp:
	def __init__(self, parent):
		self.myParent = parent
		self.myContainer1 = Frame(parent)
		self.myContainer1.pack()

		self.button1 = Button(self.myContainer1, command=self.button1Click)		# (1)
		self.button1.configure(text="OK", background="green")
		self.button1.pack(side=LEFT)
		self.button1.focus_force()

		self.button2 = Button(self.myContainer1, command=self.button2Click)		# (2)
		self.button2.configure(text="Cancel", background="red")
		self.button2.pack(side=RIGHT)

	def button1Click(self):		# (3)
		print "button1Click event handler"
		if self.button1["background"] == "green":
			self.button1["background"] = "yellow"
		else:
			self.button1["background"] = "green"

	def button2Click(self):
		print "button2Click event handler"
		self.myParent.destroy()


root = Tk()
myapp = MyApp(root)
root.mainloop()

"""
Explanation:
In this program, look at the lines with comments (1) and (2) to see how command binding is done. In
those lines, we use the "command" option to bind button1 to the "self.button1Click" event handler, and
to bind button2 to the "self.button2Click" event handler.

(3) (4)
Look at the definition of the event handlers themselves. Note that -- unlike the event handlers in the
previous program -- they are NOT expecting an event object as an argument. That is because
command binding, unlike event binding, does NOT automatically pass an event object as an argument.
And of course, this makes sense. A command binding doesn't bind a single event to a handler. It binds
multiple events to a handler. For a Button widget, for instance, it binds a pattern of a ButtonPress
followed by a ButtonRelease to a handler. If it were to pass an event to its event handler, which event
would it pass: ButtonPress or ButtonRelease? Neither would be exactly correct. This is why command
binding, unlike event binding, does not pass an event object.
"""