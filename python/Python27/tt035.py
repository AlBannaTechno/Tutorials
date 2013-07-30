from Tkinter import *

class MyApp:								# (1)
	def __init__(self, myParent):			# (1a)
		self.myContainer1 = Frame(myParent)
		self.myContainer1.pack()

		self.button1 = Button(self.myContainer1)
		self.button1["text"] = "Hello, World!"
		self.button1["background"] = "green"
		self.button1.pack()

root = Tk()
myapp = MyApp(root)		# (2)
root.mainloop()			# (3)

"""
Explanation:
(1) In our code, we define a class (MyApp) that defines how we want our GUI to look. It defines the
way we want our GUI to look and the kinds of things that we want to do with it. All of this code is put
into the constructor (__init__) method of the class. (1a)

(2) When the program executes, the first thing it does is to create an instance of the class. 

Note that the name of the class is "MyApp" (note the capitalization) and the name of the instance is
"myapp" (note the lack of capitalization).

Note also that this statement passes "root" as an argument into the constructor method (__init__) of
MyApp. The constructor method recognizes the root under the name "myParent". (1a)

(3) Finally, we run mainloop on the root.
"""