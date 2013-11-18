#ifndef MOVE_H
#define MOVE_H

#include <QtGui/QMainWindow>


class Move : public QWidget {
    Q_OBJECT

public:
    Move(QWidget *parent=0);

protected:
    void moveEvent(QMoveEvent *event);
};

#endif // MOVE_H
