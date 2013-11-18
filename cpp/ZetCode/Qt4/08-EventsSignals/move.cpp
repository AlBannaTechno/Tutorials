#include <QtGui/QMoveEvent>

#include "move.h"


Move::Move(QWidget *parent)
    : QWidget(parent) { }


void Move::moveEvent(QMoveEvent *event) {
    int x = event->pos().x();
    int y = event->pos().y();
    QString text = QString::number(x) + "," + QString::number(y);

    setWindowTitle(text);
}
