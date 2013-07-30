#!/usr/bin/env python

import math
import sys
from PySide import QtGui, QtCore

class Arrow(QtGui.QGraphicsPixmapItem):

    def __init__(self):
        QtGui.QGraphicsPixmapItem.__init__(self)
        self.setPixmap(QtGui.QPixmap("./arrow.png"))


class Example(QtGui.QGraphicsView):

    def __init__(self):
        QtGui.QGraphicsView.__init__(self)

        self.setGeometry(300, 300, 350, 350)
        self.setRenderHint(QtGui.QPainter.Antialiasing)

        policy = QtCore.Qt.ScrollBarAlwaysOff
        self.setVerticalScrollBarPolicy(policy)
        self.setHorizontalScrollBarPolicy(policy)

        self.setWindowTitle("Arrow")
        self.setMouseTracking(True) #Required or movement is only tracked when mouse1 is held down
        self.initScene()

    def initScene(self):
        self.scene = QtGui.QGraphicsScene()
        self.arrow = Arrow()
        self.scene.addItem(self.arrow)
        self.setScene(self.scene)

    def mouseMoveEvent(self, event):
        s_coords = self.sceneCoordinates(event)
        theta_deg = self.calculateAngle(s_coords)

        self.doTransform(theta_deg, s_coords[2], s_coords[3])

    def sceneCoordinates(self, event):
        point = event.pos()
        sMousePt = self.mapToScene(point.x(), point.y())

        s_mouse_x = sMousePt.x()
        s_mouse_y = sMousePt.y()

        arrowCenterPt = self.arrow.boundingRect().center()
        arrow_x = arrowCenterPt.x()
        arrow_y = arrowCenterPt.y()

        sArrowPt = self.arrow.mapToScene(arrow_x, arrow_y)
        s_arrow_x = sArrowPt.x()
        s_arrow_y = sArrowPt.y()

        return (s_mouse_x, s_mouse_y, arrow_x, arrow_y, s_arrow_x, s_arrow_y)

    def calculateAngle(self, coords):
        s_mouse_x, s_mouse_y = coords[0], coords[1]
        s_arrow_x, s_arrow_y = coords[4], coords[5]

        a = abs(s_mouse_x - s_arrow_x)
        b = abs(s_mouse_y - s_arrow_y)

        if (a == 0) and (b == 0):
            return

        elif (a == 0) and (s_mouse_y < s_arrow_y):
            theta_deg = 270

        elif (a == 0) and (s_mouse_y > s_arrow_y):
            theta_deg = 90

        else:
            theta_reg = math.atan(b / a)
            theta_deg = math.degrees(theta_reg)

            if (s_mouse_x < s_arrow_x) and (s_mouse_y > s_arrow_y):
                theta_deg = 180 - theta_deg

            elif (s_mouse_x < s_arrow_x) and (s_mouse_y < s_arrow_y):
                theta_deg = 180 + theta_deg

            elif (s_mouse_x > s_arrow_x) and (s_mouse_y < s_arrow_y):
                theta_deg = 360 - theta_deg

        return theta_deg

    def doTransform(self, theta_deg, arrow_x, arrow_y):
        transform = QtGui.QTransform()

        transform.translate(arrow_x, arrow_y)
        transform.rotate(theta_deg)
        transform.translate(-arrow_x, -arrow_y)

        self.arrow.setTransform(transform)


app = QtGui.QApplication([])
root = Example()
root.show()
sys.exit(app.exec_())