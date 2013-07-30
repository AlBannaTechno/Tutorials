#!/usr/bin/env python
# -*- encoding: utf-8 -*-

import random
from PySide import QtCore, QtGui


# Global variables
WIDTH = 250
HEIGHT = 290

NUM_IMAGES = 13
CELL_SIZE = 15

COVER_FOR_CELL = 10
MARK_FOR_CELL = 10
EMPTY_CELL = 0
MINE_CELL = 9
COV_MINE_CELL = MINE_CELL + COVER_FOR_CELL
MARKED_MINE_CELL = COV_MINE_CELL + MARK_FOR_CELL

DRAW_MINE = 9
DRAW_COVER = 10
DRAW_MARK = 11
DRAW_WRONG_MARK = 12

img = [0] * NUM_IMAGES


class Board(QtGui.QWidget):
    def __init__(self, statusbar):
        QtGui.QWidget.__init__(self)

        self.statusbar = statusbar
        self.initGame()
        self.newGame()

    def initGame(self):
        self.field = []
        self.in_game = False
        self.mines_left = 0

        self.mines = 40
        self.rows = 16
        self.cols = 16
        self.all_cells = 0

        for i in range(NUM_IMAGES):
            img[i] = QtGui.QImage('./{0}'.format(i))

    def newGame(self):
        i = 0
        position = 0
        cell = 0

        self.in_game = True
        self.mines_left = self.mines

        self.all_cells = self.rows * self.cols
        self.field = [0] * self.all_cells

        for i in range(self.all_cells):
            self.field[i] = COVER_FOR_CELL

        self.statusbar.showMessage(str(self.mines_left))

        i = 0
        while i < self.mines:
            position = random.randint(0, self.all_cells)

            if position < self.all_cells and self.field[position] != COV_MINE_CELL:
                current_col = position % self.cols
                self.field[position] = COV_MINE_CELL
                i += 1

                if current_col > 0:

                    cell = position - 1 - self.cols
                    if cell >= 0:
                        if self.field[cell] != COV_MINE_CELL:
                            self.field[cell] += 1

                    cell = position - 1
                    if cell >= 0:
                        if self.field[cell] != COV_MINE_CELL:
                            self.field[cell] += 1

                    cell = position + self.cols - 1
                    if cell < self.all_cells:
                        if self.field[cell] != COV_MINE_CELL:
                            self.field[cell] += 1

                cell = position - self.cols
                if cell >= 0:
                    if self.field[cell] != COV_MINE_CELL:
                        self.field[cell] += 1

                cell = position + self.cols
                if cell < self.all_cells:
                    if self.field[cell] != COV_MINE_CELL:
                        self.field[cell] += 1

                if current_col < self.cols - 1:
                    cell = position - self.cols + 1

                    if cell >= 0:
                        if self.field[cell] != COV_MINE_CELL:
                            self.field[cell] += 1

                    cell = position + self.cols + 1
                    if cell < self.all_cells:
                        if self.field[cell] != COV_MINE_CELL:
                            self.field[cell] += 1

                    cell = position + 1
                    if cell < self.all_cells:
                        if self.field[cell] != COV_MINE_CELL:
                            self.field[cell] += 1

    def findEmptyCells(self, j):
        current_col = j % self.cols
        cell = 0

        if current_col > 0:

            cell = j - self.cols - 1
            if cell >= 0:
                if self.field[cell] > MINE_CELL:
                    self.field[cell] -= COVER_FOR_CELL
                    if self.field[cell] == EMPTY_CELL:
                        self.findEmptyCells(cell)

            cell = j - 1
            if cell >= 0:
                if self.field[cell] > MINE_CELL:
                    self.field[cell] -= COVER_FOR_CELL
                    if self.field[cell] == EMPTY_CELL:
                        self.findEmptyCells(cell)

            cell = j + self.cols - 1
            if cell < self.all_cells:
                if self.field[cell] > MINE_CELL:
                    self.field[cell] -= COVER_FOR_CELL
                    if self.field[cell] == EMPTY_CELL:
                        self.findEmptyCells(cell)

        cell = j - self.cols
        if cell >= 0:
            if self.field[cell] > MINE_CELL:
                self.field[cell] -= COVER_FOR_CELL
                if self.field[cell] == EMPTY_CELL:
                    self.findEmptyCells(cell)

        cell = j + self.cols
        if cell < self.all_cells:
            if self.field[cell] > MINE_CELL:
                self.field[cell] -= COVER_FOR_CELL
                if self.field[cell] == EMPTY_CELL:
                    self.findEmptyCells(cell)

        if current_col < self.cols - 1:
            cell = j - self.cols + 1
            if cell >= 0:
                if self.field[cell] > MINE_CELL:
                    self.field[cell] -= COVER_FOR_CELL
                    if self.field[cell] == EMPTY_CELL:
                        self.findEmptyCells(cell)

        cell = j + self.cols + 1
        if cell < self.all_cells:
            if self.field[cell] > MINE_CELL:
                self.field[cell] -= COVER_FOR_CELL
                if self.field[cell] == EMPTY_CELL:
                    self.findEmptyCells(cell)

        cell = j + 1
        if cell < self.all_cells:
            if self.field[cell] > MINE_CELL:
                self.field[cell] -= COVER_FOR_CELL
                if self.field[cell] == EMPTY_CELL:
                    self.findEmptyCells(cell)

    def paintEvent(self, event):
        QtGui.QWidget.paintEvent(self, event)

        painter = QtGui.QPainter()
        painter.begin(self)
        self.drawBoard(painter)
        painter.end()

    def drawBoard(self, painter):
        cell = 0
        uncover = 0

        for i in range(self.rows):
            for j in range(self.cols):
                cell = self.field[(i * self.cols) + j]

                if not self.in_game:
                    if cell == COV_MINE_CELL:
                        cell = DRAW_MINE
                    elif cell == MARKED_MINE_CELL:
                        cell = DRAW_MARK
                    elif cell > COV_MINE_CELL:
                        cell = DRAW_WRONG_MARK
                    elif cell > MINE_CELL:
                        cell = DRAW_COVER

                else:
                    if cell > COV_MINE_CELL:
                        cell = DRAW_MARK
                    elif cell > MINE_CELL:
                        cell = DRAW_COVER

                painter.drawImage(j * CELL_SIZE, i * CELL_SIZE, img[cell])

    def mousePressEvent(self, event):
        x = event.x()
        y = event.y()

        cell_col = x / CELL_SIZE
        cell_row = y / CELL_SIZE

        rep = False

        if not self.in_game:
            self.newGame()
            self.repaint()
            return

        pos = (cell_row * self.cols) + cell_col
        if x < self.cols * CELL_SIZE and y < self.rows * CELL_SIZE:

            if event.button() == QtCore.Qt.RightButton:
                if self.field[pos] > MINE_CELL:
                    rep = True

                    if self.field[pos] <= COV_MINE_CELL:
                        if self.mines_left > 0:
                            self.field[pos] += MARK_FOR_CELL
                            self.mines_left -= 1
                            self.statusbar.showMessage(str(self.mines_left))
                        else:
                            self.statusbar.showMessage('No marks left.')
                    else:
                        self.field[pos] -= MARK_FOR_CELL
                        self.mines_left += 1
                        self.statusbar.showMessage(str(self.mines_left))

            else:
                if self.field[pos] == MARKED_MINE_CELL:
                    return

                if self.field[pos] > MINE_CELL and self.field[pos] < MARKED_MINE_CELL:
                    self.field[pos] -= COVER_FOR_CELL
                    rep = True

                    if self.field[pos] == MINE_CELL:
                        self.in_game = False
                        self.statusbar.showMessage('Game lost')
                    if self.field[pos] == EMPTY_CELL:
                        self.findEmptyCells(pos)

            uncovered = 0
            for cell in range(self.all_cells):
                if self.field[cell] < MINE_CELL:
                    uncovered += 1

                if self.mines_left == 0 and uncovered == (self.all_cells - self.mines):
                    self.in_game = False
                    self.statusbar.showMessage('Game won!')

            if rep:
                self.repaint()


class Mines(QtGui.QMainWindow):
    def __init__(self):
        QtGui.QMainWindow.__init__(self)

        self.setWindowTitle('Minesweeper')
        self.resize(WIDTH, HEIGHT)
        policy = QtGui.QSizePolicy.Fixed
        self.setSizePolicy(policy, policy)

        self.statusbar = self.statusBar()
        self.setCentralWidget(Board(self.statusbar))

        self.move(300, 300)


if __name__ == '__main__':
    import sys

    app = QtGui.QApplication([])
    root = Mines()
    root.show()

    sys.exit(app.exec_())