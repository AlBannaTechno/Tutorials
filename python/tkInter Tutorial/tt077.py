from Tkinter import *

class MyApp:
	def __init__(self, parent):
		self.myParent = parent
		self.myContainer1 = Frame(parent)
		self.myContainer1.pack()

		button_name = "OK"
		self.button1 = Button(self.myContainer1, command=self.buttonHandler(button_name, 1, "Good Stuff!"))
		# self.button1.bind("<Return>", self.buttonHandler_a(event, button_name, 1, "Good Stuff!"))
		self.button1.configure(text=button_name, background="green")
		self.button1.pack(side=LEFT)
		self.button1.focus_force()		# Put keyboard focus on button1

		button_name = "Cancel"
		self.button2 = Button(self.myContainer1, command=self.buttonHandler(button_name, 2, "Bad Stuff!"))
		# self.button2.bind("<Return>", self.buttonHandler_a(event, button_name, 2, "Bad Stuff"))
		self.button2.configure(text=button_name, background="red")
		self.button2.pack(side=LEFT)

	def buttonHandler(self, arg1, arg2, arg3):
		print "\tbuttonHandler routine received arguments:", arg1.ljust(8), arg2, arg3

	def buttonHandler_a(self, event, arg1, arg2, arg3):
		print "buttonHandler_a received event", event
		self.buttonHandler(arg1, arg2, arg3)


print "\n"*100 		# clear the screen
print "Starting program tt077..."
root = Tk()
myapp = MyApp(root)
print "Ready to start executing the event loop..."
root.mainloop()
print "Finished executing the event loop..."

"""
Explanation:
In this program, as you can see, we have two buttons, and we use the "command" option to bind them
all to the same event handler -- the "buttonHandler" routine. We pass the buttonHandler routine three
arguments: the name of the button (in the button_name variable), a number, and a string.

In a serious application, the buttonHandler routine would of course do serious work, but in this program
it merely prints the arguments that it receives.

You will note that we have commented out the two lines that do event binding on the <Return> event.

This is the first sign of a problem. Event binding automatically passes an event argument -- but there is
simply no way to include that event argument in our list of arguments.

When you look at the code, this program looks quite reasonable. But when you run it, you will see that
it doesn't work right. The buttonHandler routine is invoked even before the GUI is displayed. In fact, it
is invoked TWO times!

And if you left-mouse-click on any of the buttons, you will find that nothing happens -- the
"eventHandler" routine is *not* being invoked.
"""