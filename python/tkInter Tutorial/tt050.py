from Tkinter import *

class MyApp:
	def __init__(self, parent):
		self.myContainer1 = Frame(parent)
		self.myContainer1.pacl()

		self.button1 = Button(self.myContainer1)
		self.button1["text"] = "Hello, World!"
		self.button1["background"] = "green"
		self.button1.pack(side=LEFT)	# (1)

		self.button2 = Button(self.myContainer1)
		self.button2.configure(text="Off to join the circus!")
		self.button2.configure(background="tan")
		self.button2.pack(side=LEFT)	# (2)

		self.button3 = Button(self.myContainer1)
		self.button3.configure(text="Join me?", background="cyan")
		self.button3.pack(side=LEFT)	# (3)

		self.button3 = Button(self.myContainer1, text="Goodbye!", background="red")
		self.button3.pack(side=LEFT)	# (4)


root = Tk()
myapp = MyApp(root)
root.mainloop()

"""
Explanation:
(1) (2) (3) (4)
Packing is a way of controlling the VISUAL relationship of components. So what we are going to do now
is to use the pack "side" option to put the buttons side-by-side rather than stacked on top of each
other. We do it with the "side" argument to the pack() statement.

Note that LEFT (like RIGHT, TOP, and BOTTOM) are user-friendly constants defined in Tkinter. That is,
"LEFT" is actually "Tkinter.LEFT" -- but because of the way that we imported Tkinter, we don't need to
supply the "Tkinter." prefix.
"""