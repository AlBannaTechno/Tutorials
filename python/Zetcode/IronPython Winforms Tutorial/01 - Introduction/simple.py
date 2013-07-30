#!/usr/bin/env ironpython
# -*- encoding: utf-8 -*-

import clr
clr.AddReference("System.Windows.Forms")

from System.Windows.Forms import Application, Form


class IForm(Form):
    
    def __init__(self):
        self.Text = "Simple"
        self.Width = 250
        self.Height = 200
        self.CenterToScreen()
        
        
if __name__ == "__main__":
    Application.Run(IForm())