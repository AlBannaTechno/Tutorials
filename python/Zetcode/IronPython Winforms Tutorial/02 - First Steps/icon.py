#!/usr/bin/env ironpython
# -*- encoding: utf-8 -*-

import clr
import sys

clr.AddReference("System.Windows.Forms")
clr.AddReference("System.Drawing")

from System.Windows.Forms import Application, Form
from System.Drawing import Icon


class IForm(Form):
    
    def __init__(self):
        self.Text = "Icon"
        self.Width = 250
        self.Height = 200
        
        try:
            self.Icon = Icon("Web.ico")
        
        except Exception, e:
            print e
            sys.exit(1)
            
            
if __name__ == "__main__":
    Application.Run(IForm())