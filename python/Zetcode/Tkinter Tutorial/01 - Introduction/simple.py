#!/usr/bin/env python
# -*- encoding: utf-8 -*-

import Tkinter


class Example(Tkinter.Frame):
    def __init__(self, parent):
        Tkinter.Frame.__init__(self, parent, background="white")
        self.parent = parent
        self.initUi()

    def initUi(self):
        self.parent.title('Simple')
        self.pack(fill=Tkinter.BOTH, expand=1)


if __name__ == '__main__':
    root = Tkinter.Tk()
    root.geometry("250x150+300+300")
    app = Example(root)
    root.mainloop()
