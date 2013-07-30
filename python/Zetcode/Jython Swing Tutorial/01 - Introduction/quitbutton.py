#!/usr/bin/env jython
# -*- encoding: utf-8 -*-

from java.lang import System
from javax.swing import JFrame
from javax.swing import JPanel
from javax.swing import JButton


class Example(JFrame):
    
    def __init__(self):
        JFrame.__init__(self)
        self.initUI()
        
    def initUI(self):
        panel = JPanel()
        self.getContentPane().add(panel)
        panel.setLayout(None)
        
        qbutton = JButton("Quit", actionPerformed=self.onQuit)
        qbutton.setBounds(50, 60, 80, 30)
        
        panel.add(qbutton)
        
        self.setTitle("Quit Button")
        self.setSize(300, 200)
        self.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE)
        self.setLocationRelativeTo(None)
        self.setVisible(True)
        
    def onQuit(self, e):
        System.exit(0)
        
        
if __name__ == "__main__":
    Example()