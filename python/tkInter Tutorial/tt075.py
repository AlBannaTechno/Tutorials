from Tkinter import *

class MyApp:
	def __init__(self, parent):
		self.myParent = parent
		self.myContainer1 = Frame(parent)
		self.myContainer1.pack()

		self.button1 = Button(self.myContainer1, command=self.button1Click)
		self.button1.bind("<Return>", self.button1Click_a)			# (1)
		self.button1.configure(text="OK", background="green")
		self.button1.pack(side=LEFT)
		self.button1.focus_force()

		self.button2 = Button(self.myContainer1, command=self.button2Click)
		self.button2.bind("<Return>", self.button2Click_a)			# (1)
		self.button2.configure(text="Cancel", background="red")
		self.button2.pack(side=RIGHT)

	def button1Click(self):		# (2)
		print "button1Click event handler"
		if self.button1["background"] == "green":
			self.button1["background"] = "yellow"
		else:
			self.button1["background"] = "green"

	def button2Click(self):		# (2)
		print "button2Click event handler"
		self.myParent.destroy()

	def button1Click_a(self, event):		# (3)
		print "button1Click_a event handler (a wrapper)"
		self.button1Click()

	def button2Click_a(self, event):		# (3)
		print "button2Click_a event handler (a wrapper)"
		self.button2Click()


root = Tk()
myapp = MyApp(root)
root.mainloop()

"""
Explanation:
We noted in our last program that command binding, unlike event binding, does NOT automatically pass
an event object as an argument. This can make life a little complicated if you want to bind an event
handler to a widget using *both* event binding *and* command binding.

For example, in this program we really would like our buttons to respond to presses of the RETURN key
as well as the spacebar. But to get them to do that, we will have to use event binding to the <Return>
keyboard event, like we did in our earlier program. (1)

The problem is that the command binding will not pass an event object as an argument, but the event
binding will. So how should we write our event handler?

There are a number of solutions to this problem, but the simplest is to write two event handlers. The
"real" event handler (2) will be the one used by the "command" binding, and it won't expect an event
object.

The other event handler (3) will just be a wrapper for the real event-handler. This wrapper will expect
the event-object argument, but will ignore it and call the real event-handler without it. We will give the
wrapper the same name as the real event-handler, but with an added "_a" suffix.
"""