from Tkinter import *

class MyApp:
	def __init__(self, parent):

		### 1 -- At the outset, we havn't yet invoked any button handler
		self.myLastButtonInvoked = None

		self.myParent = parent
		self.myContainer1 = Frame(parent)
		self.myContainer1.pack()

		self.yellowButton = Button(self.myContainer1, command=self.yellowButtonClick)
		self.yellowButton.configure(text="YELLOW", background="yellow")
		self.yellowButton.pack(side=LEFT)

		self.redButton = Button(self.myContainer1, command=self.redButtonClick)
		self.redButton.configure(text="RED", background="red")
		self.redButton.pack(side=LEFT)

		self.whiteButton = Button(self.myContainer1, command=self.whiteButtonClick)
		self.whiteButton.configure(text="WHITE", background="white")
		self.whiteButton.pack(side=LEFT)

	def redButtonClick(self):
		print "RED 	button clicked. Previous button invoked was", self.myLastButtonInvoked
		self.myLastButtonInvoked = "RED"	# (1)
	
	def yellowButtonClick(self):
		print "YELLOW 	button clicked. Previous button invoked was", self.myLastButtonInvoked
		self.myLastButtonInvoked = "YELLOW"	# (1)

	def whiteButtonClick(self):
		print "WHITE 	button clicked. Previous button invoked was", self.myLastButtonInvoked
		self.myLastButtonInvoked = "WHITE"	# (1)


print "\n"*100	# a simple way to clear the screen
print "Starting..."
root = Tk()
myapp = MyApp(root)
root.mainloop()
print "... Done!"

"""
Explanation:
In this program, we are going to remember and share a very simple piece of information: the name of
the last button that was invoked. We will store it in an instance variable called
"self.myLastButtonInvoked". [see ### 1 comments]

And to show that we actually are remembering this information, whenever a button handler is invoked,
it will print out this information. [see ### 2 comments]
"""