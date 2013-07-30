#!/usr/bin/env python
# -*- encoding: utf-8 -*-

import sys
from PySide import QtCore, QtGui


SPACE = 20
OFFSET = 30
LEFT_COLLISION = 1
RIGHT_COLLISION = 2
TOP_COLLISION = 3
BOTTOM_COLLISION = 4

level = """
    ######
    ##   #
    ##$  #
  ####  $##
  ##  $ $ #
#### # ## #   ######
##   # ## #####  ..#
## $  $          ..#
###### ### #@##  ..#
    ##     #########
    ########
"""


class Actor(object):
    def __init__(self, x, y):
        self._x = x
        self._y = y

    def getImage(self):
        return self.image

    @property
    def x(self):
        return self._x

    @property
    def y(self):
        return self._y

    @x.setter
    def x(self, x):
        self._x = x

    @y.setter
    def y(self, y):
        self._y = y

    def isLeftCollision(self, actor):
        if ((self.x - SPACE) == actor.x) and (self.y == actor.y):
            return True
        else:
            return False

    def isRightCollision(self, actor):
        if ((self.x + SPACE) == actor.x) and (self.y == actor.y):
            return True
        else:
            return False

    def isTopCollision(self, actor):
        if (self.x == actor.x) and ((self.y - SPACE) == actor.y):
            return True
        else:
            return False

    def isBottomCollision(self, actor):
        if (self.x == actor.x) and ((self.y + SPACE) == actor.y):
            return True
        else:
            return False


class Baggage(Actor):
    def __init__(self, x, y):
        Actor.__init__(self, x, y)

        try:
            self.image = QtGui.QImage('./baggage.png')
        except Exception as error:
            print error
            sys.exit(1)

    def move(self, x, y):
        self.x += x
        self.y += y


class Player(Actor):
    def __init__(self, x, y):
        Actor.__init__(self, x, y)

        try:
            self.image = QtGui.QImage('./sokoban.png')
        except Exception as error:
            print error
            sys.exit(1)

    def move(self, x, y):
        self.x += x
        self.y += y


class Wall(Actor):
    def __init__(self, x, y):
        Actor.__init__(self, x, y)

        try:
            self.image = QtGui.QImage('./wall.png')
        except Exception as error:
            print error
            sys.exit(1)


class Area(Actor):
    def __init__(self, x, y):
        Actor.__init__(self, x, y)

        try:
            self.image = QtGui.QImage('./area.png')
        except Exception as error:
            print error
            sys.exit(1)


class Board(QtGui.QWidget):
    def __init__(self):
        QtGui.QWidget.__init__(self)

        self.setFocusPolicy(QtCore.Qt.StrongFocus)

        self.world = []
        self.walls = []
        self.baggs = []
        self.areas = []

        self.w = 0
        self.h = 0

        self.completed = False
        self.soko = None

        self.initWorld()
        self.resize(self.w, self.h)

    def getWidth(self):
        return self.w

    def getHeight(self):
        return self.h

    def initWorld(self):
        x = OFFSET
        y = OFFSET

        for i in range(len(level)):
            item = level[i]

            if item == '\n':
                y += SPACE
                if self.w < x:
                    self.w = x
                x = OFFSET

            elif item == '#':
                w = Wall(x, y)
                self.walls.append(w)
                x += SPACE

            elif item == '$':
                b = Baggage(x, y)
                self.baggs.append(b)
                x += SPACE

            elif item == '.':
                a = Area(x, y)
                self.areas.append(a)
                x += SPACE

            elif item == '@':
                self.soko = Player(x, y)
                x += SPACE

            elif item == ' ':
                x += SPACE

        self.h = y

    def buildWorld(self, painter):
        painter.setBrush(QtGui.QColor(250, 240, 170))
        painter.setPen(QtGui.QColor(250, 240, 170))
        painter.drawRect(0, 0, self.width(), self.height())
        painter.setPen(QtGui.QColor(0, 0, 0))

        world = self.walls + self.areas + self.baggs + [self.soko]

        for i in range(len(world)):
            item = world[i]

            if isinstance(item, Player) or isinstance(item, Baggage):
                painter.drawImage(item.x + 2, item.y + 2, item.getImage())

            else:
                painter.drawImage(item.x, item.y, item.getImage())

        if self.completed:
            painter.drawText(25, 20, 'Completed')

    def paintEvent(self, event):
        QtGui.QWidget.paintEvent(self, event)

        painter = QtGui.QPainter()
        painter.begin(self)
        self.buildWorld(painter)
        painter.end()

    def keyReleaseEvent(self, event):
        if self.completed:
            return

        key = event.key()

        if key == QtCore.Qt.Key_Left:
            if self.checkWallCollision(self.soko, LEFT_COLLISION):
                return
            if self.checkBagCollision(LEFT_COLLISION):
                return
            self.soko.move(-SPACE, 0)

        elif key == QtCore.Qt.Key_Right:
            if self.checkWallCollision(self.soko, RIGHT_COLLISION):
                return
            if self.checkBagCollision(RIGHT_COLLISION):
                return
            self.soko.move(SPACE, 0)

        elif key == QtCore.Qt.Key_Up:
            if self.checkWallCollision(self.soko, TOP_COLLISION):
                return
            if self.checkBagCollision(TOP_COLLISION):
                return
            self.soko.move(0, -SPACE)

        elif key == QtCore.Qt.Key_Down:
            if self.checkWallCollision(self.soko, BOTTOM_COLLISION):
                return
            if self.checkBagCollision(BOTTOM_COLLISION):
                return
            self.soko.move(0, SPACE)

        elif key == QtCore.Qt.Key_R:
            self.restartLevel()

        self.repaint()

    def checkWallCollision(self, actor, _type):
        if _type == LEFT_COLLISION:
            for i in range(len(self.walls)):
                wall = self.walls[i]
                if actor.isLeftCollision(wall):
                    return True
            return False

        elif _type == RIGHT_COLLISION:
            for i in range(len(self.walls)):
                wall = self.walls[i]
                if actor.isRightCollision(wall):
                    return True
            return False

        elif _type == TOP_COLLISION:
            for i in range(len(self.walls)):
                wall = self.walls[i]
                if actor.isTopCollision(wall):
                    return True
            return False

        elif _type == BOTTOM_COLLISION:
            for i in range(len(self.walls)):
                wall = self.walls[i]
                if actor.isBottomCollision(wall):
                    return True
            return False

    def checkBagCollision(self, _type):
        if _type == LEFT_COLLISION:
            for i in range(len(self.baggs)):
                bag = self.baggs[i]
                if self.soko.isLeftCollision(bag):
                    for j in range(len(self.baggs)):
                        item = self.baggs[j]
                        if not bag is item:
                            if bag.isLeftCollision(item):
                                return True
                        if self.checkWallCollision(bag, LEFT_COLLISION):
                            return True
                    bag.move(-SPACE, 0)
                    self.isCompleted()
            return False

        elif _type == RIGHT_COLLISION:
            for i in range(len(self.baggs)):
                bag = self.baggs[i]
                if self.soko.isRightCollision(bag):
                    for j in range(len(self.baggs)):
                        item = self.baggs[j]
                        if not bag is item:
                            if bag.isRightCollision(item):
                                return True
                        if self.checkWallCollision(bag, RIGHT_COLLISION):
                            return True
                    bag.move(SPACE, 0)
                    self.isCompleted()
            return False

        elif _type == TOP_COLLISION:
            for i in range(len(self.baggs)):
                bag = self.baggs[i]
                if self.soko.isTopCollision(bag):
                    for j in range(len(self.baggs)):
                        item = self.baggs[j]
                        if not bag is item:
                            if bag.isTopCollision(item):
                                return True
                        if self.checkWallCollision(bag, TOP_COLLISION):
                            return True
                    bag.move(0, -SPACE)
                    self.isCompleted()
            return False

        elif _type == BOTTOM_COLLISION:
            for i in range(len(self.baggs)):
                bag = self.baggs[i]
                if self.soko.isBottomCollision(bag):
                    for j in range(len(self.baggs)):
                        item = self.baggs[j]
                        if not bag is item:
                            if bag.isBottomCollision(item):
                                return True
                        if self.checkWallCollision(bag, BOTTOM_COLLISION):
                            return True
                    bag.move(0, SPACE)
                    self.isCompleted()
            return False

    def isCompleted(self):
        num = len(self.baggs)
        completed = 0

        for i in range(num):
            bag = self.baggs[i]
            for j in range(num):
                area = self.areas[j]
                if (bag.x == area.x) and (bag.y == area.y):
                    completed += 1

        if completed == num:
            self.completed = True
            self.repaint()

    def restartLevel(self):
        del self.areas[:]
        del self.baggs[:]
        del self.walls[:]
        self.initWorld()

        if self.completed:
            self.completed = False


class Sokoban(QtGui.QMainWindow):
    def __init__(self):
        QtGui.QMainWindow.__init__(self)

        self.initUI()

    def initUI(self):
        self.setWindowTitle('Sokoban')
        board = Board()
        self.setCentralWidget(board)
        self.resize(board.getWidth() + OFFSET, board.getHeight() + OFFSET)
        self.move(300, 300)


if __name__ == '__main__':
    app = QtGui.QApplication([])
    root = Sokoban()
    root.show()

    sys.exit(app.exec_())