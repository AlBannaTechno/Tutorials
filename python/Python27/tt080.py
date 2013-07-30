from Tkinter import *

class MyApp:
	def __init__(self, parent):
		#------ constants for controlling layout ------
		button_width = 6		# (1)

		button_padx = "2m"		# (2)
		button_pady = "1m"		# (2)

		buttons_frame_padx = "3m"	# (3)
		buttons_frame_pady = "2m"	# (3)
		buttons_frame_ipadx = "3m"	# (3)
		buttons_frame_ipady = "1m"	# (3)
		# -------------- end constants --------------

		self.myParent = parent
		self.buttons_frame = Frame(parent)

		self.buttons_frame.pack(		# (4)
			ipadx=buttons_frame_ipadx,	# (3)
			ipady=buttons_frame_ipady,	# (3)
			padx=buttons_frame_padx,	# (3)
			pady=buttons_frame_pady,	# (3)
			)
		
		self.button1 = Button(self.buttons_frame, command=self.button1Click)
		self.button1.configure(text="OK", background="green")
		self.button1.focus_force()
		self.button1.configure(
			width=button_width,		# (1)
			padx=button_padx,		# (2)
			pady=button_pady,		# (2)
			)
		
		self.button1.pack(side=LEFT)
		self.button1.bind("<Return>", self.button1Click_a)

		self.button2 = Button(self.buttons_frame, command=self.button2Click)
		self.button2.configure(text="Cancel", background="red")
		self.button2.configure(
			width=button_width,		# (1)
			padx=button_padx,		# (2)
			pady=button_pady,		# (2)
			)
		
		self.button2.pack(side=LEFT)
		self.button2.bind("<Return>", self.button2Click_a)
	
	def button1Click(self):
		if self.button1["background"] == "green":
			self.button1["background"] = "yellow"
		else:
			self.button1["background"] = "green"

	def button2Click(self):
		self.myParent.destroy()

	def button1Click_a(self, event):
		self.button1Click()
	
	def button2Click_a(self, event):
		self.button2Click()


root = Tk()
myapp = MyApp(root)
root.mainloop()

"""
Explanation: 
(1) First, to make sure that all of our buttons are the same width, we specify a "width" attribute that is
the same for all of them. Note that the "width" attribute is specific to Tkinter's "Button" widget -- not all
widgets have a width attribute. Note also that the width attribute is specified in units of characters (not,
for example, in units of pixels, inches, or millimeters). Since our longest label ("Cancel") contains six
characters, we set the width for our buttons to "6". (1)

(2) Now we add some padding to our buttons. Padding is extra space that goes around the text,
between the text and the edge of the button. We do this by setting the "padx" and "pady" attributes of
the buttons. "padx" pads along the X-axis, horizontally, to the left and right. "pady" pads along the
Y-axis, vertically, to the top and bottom.

We will specify our horizontal padding as 3 millimeters (padx="3m") and our vertical padding as 1
millimeter (pady="1m"). Note that, unlike the "width" attribute (which was numeric), these attributes
are enclosed in quotation marks. That is because we are specifying the units of padding with the "m"
suffix, so we must specify the padding lengths as strings rather than as numbers.

(3) Finally, we add some padding to the container (buttons_frame) that holds the buttons. For the
container, we can specify four padding attributes. "padx" and "pady" specify the padding that goes
around (outside) the frame. "ipadx" and "ipady" ("internal padx" and "internal pady") specify the
internal padding. This is padding that goes around each of the widgets that are inside the container.

Notice that we don't specify the padding for the frame as an attribute of the frame, but as options that
we pass to the packer. (4). As you can see, the padding is a bit confusing. Frames have internal
padding, but widget such as buttons do not. In some cases, the padding is an attribute of the widget,
while in other cases it is specified as an option to pack().
"""