from Tkinter import *

root = Tk()

myContainer1 = Frame(root)	# (1)
myContainer1.pack()			# (2)

root.mainloop()

"""
Explanation:
(1) creates a frame whose parent is myParent (that is, root), and gives it the name "myContainer1". In
short, it creates a container into which we can put widgets. (We won't put any widgets into in this
program. We'll do that in later programs.)

Note that the parent/child relationship here is a LOGICAL one, not a visual one. This relationship exists
to support such things as the destroy event -- so that when a parent component (such as the root) is
destroyed, the parent knows who its children are, and can destroy them before destroying itself.

(2) The next statement "packs" myContainer1.

Simply put, "packing" is a process of setting up a VISUAL relationship between a GUI component and its
parent. If you don't pack a component, you will never see it.

"Pack" invokes the Tkinter "pack" geometry manager. A geometry manager is essentially an API -- a
way of talking to Tkinter -- for telling Tkinter how you want containers and widgets to be visually
presented. Tkinter supports three geometry managers: pack, grid, and place. Pack (and to a lesser
extent) grid are the most widely used, because they are the easiest to use. All of the examples in
"Thinking in Tkinter" use the pack geometry manager.

So here you see a basic pattern for Tkinter programming that we will see over and over again.
(1) an instance (of a widget or a container) is created, and associated with its parent
(2) the instance is packed.
"""