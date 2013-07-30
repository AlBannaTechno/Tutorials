from Tkinter import *

class MyApp:
	def __init__(self, parent):
		self.myParent = parent
		self.myContainer1 = Frame(parent)
		self.myContainer1.pack()

		self.button1 = Button(self.myContainer1)
		self.button1.configure(text="OK", background="green")
		self.button1.pack(side=LEFT)
		self.button1.focus_force()								# (0)
		self.button1.bind("<Button-1>", self.button1Click)
		self.button1.bind("<Return>", self.button1Click)		# (1)

		self.button2 = Button(self.myContainer1)
		self.button2.configure(text="Cancel", background="red")
		self.button2.pack(side=RIGHT)
		self.button2.bind("<Button-1>", self.button2Click)
		self.button2.bind("<Return>", self.button2Click)		# (2)

	def button1Click(self, event):
		report_event(event)			# (3)
		if self.button1["background"] == "green":
			self.button1["background"] = "yellow"
		else:
			self.button1["background"] = "green"

	def button2Click(self, event):
		report_event(event)			# (4)
		self.myParent.destroy()

def report_event(event):	# (5)
	""" Print a description of an event, based on its attributes.
	"""
	event_name = {"2": "KeyPress", "4": "ButtonPress"}
	print "Time:", str(event.time)	# (6)
	print "EventType=" + str(event.type), \
		event_name[str(event.type)], \
		"EventWidgetID=" + str(event.widget), \
		"EventKeySymbol=" + str(event.keysym)


root = Tk()
myapp = MyApp(root)
root.mainloop()

"""
Explanation:
(0) In this program, we would like the OK button to have focus from the very beginning. So we use the
"focus_force()" method, which forces the focus to go to the OK button. When you run this program, you
will see that the OK button has focus from the time the application starts.

In the last program, our buttons responded to only one keyboard event -- a keypress of the TAB key --
which moved the focus back and forth between the two buttons. But if you hit the ENTER/RETURN key
on the keyboard, nothing happened. That is because we had bound only mouse clicks, not keyboard
events, to our buttons.

In this program we will also bind keyboard events to the buttons.

(1) (2) The statements to bind keyboard events to the buttons are quite simple -- they have the same
format as statements to bind mouse events. The only difference is that the name of the event is the
name of a keyboard event (in this case, "<Return>") rather than a mouse event.

We want a press of the RETURN key on the keyboard and a click of the left mouse button to have the
same effect on the widget, so we bind the same event handler to both types of events.

This program shows that you can bind multiple types of events to a single widget (such as a button).
And you can bind multiple <widget, event> combinations to the same event handler.

(3) (4) Now that our button widgets respond to multiple kinds of events, we can demonstrate how to
retrieve information from an event object. What we will do is to pass the event objects to (5) a
"report_event" routine that will (6) print out information about the event that it obtains from the event's
attributes.
"""