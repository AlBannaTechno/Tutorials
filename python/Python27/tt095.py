from Tkinter import *

class App:
	def __init__(self, root, use_geometry, show_buttons):
		fm = Frame(root, width=300, height=200, bg="blue")
		fm.pack(side=TOP, expand=NO, fill=NONE)

		if use_geometry:
			root.geometry("600x400")	# (1) Note geometry window manager method

		if show_buttons:
			Button(fm, text="Button 1", width=10).pack(side=LEFT)
			Button(fm, text="Button 2", width=10).pack(side=LEFT)
			Button(fm, text="Button 3", width=10).pack(side=LEFT)


case = 0
for use_geometry in (0, 1):
	for show_buttons in (0, 1):
		case = case + 1
		root = Tk()
		root.wm_title("Case " + str(case)) 		# (2) note wm_title window manager method
		display = App(root, use_geometry, show_buttons)
		root.mainloop()

"""
Explanation:
(1)
In this program, we use the geometry option to make a nice big window around our smaller frame.

(2) Note that the "title" option, which we also use in this program, is also a Window Manager method.
"Title" controls the text of the title in the window's title bar.

Note also that Window Manager options can optionally be specified with a "wm_" prefix, e.g.
"wm_geometry" and "wm_title". In this program, just to show that it can be done either way, we use
"geometry" and "wm_title".
"""