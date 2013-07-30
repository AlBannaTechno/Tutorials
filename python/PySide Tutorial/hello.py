#!/usr/bin/python

# Import PySide classes
import sys
from PySide.QtGui import *
from PySide.QtCore import *

# Create a Qt application
app = QApplication(sys.argv)
# Create a Label and show it
label = QLabel('<font color=red size=40>Hello World</font>')
label.show()
# Enter Qt application main loop
app.exec_()
sys.exit()