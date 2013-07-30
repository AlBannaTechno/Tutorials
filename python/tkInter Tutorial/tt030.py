from Tkinter import *

root = Tk()

myContainer1 = Frame(root)
myContainer1.pack()

button1 = Button(myContainer1)		# (1)
button1["text"] = "Hello, World!"	# (2)
button1["background"] = "green"		# (3)
button1.pack()						# (4)

root.mainloop()

"""
Explanation:
(1) The widget will be a button -- that is, it will be an instance of the Tkinter "Button" class. The
statement creates the button, gives it the name "button1", and associates it with its parent, the 
container object called myContainer1.

(2)(3) Widgets have many attributes, which are stored in their local namespace dictionary. Button
widgets have attributes to control their size, their foreground and background colors, the text that they
display, how their borders look, and so on. In this example, we will set just two of button1's attributes:
the background color and the text. We do it by setting the values in the button's dictionary with the
keys "text" and "background".

(4) And of course, we pack button1.
"""