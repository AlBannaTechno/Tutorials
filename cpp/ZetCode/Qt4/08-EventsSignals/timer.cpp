#include <QtCore/QTime>

#include "timer.h"


Timer::Timer(QWidget *parent)
    : QWidget(parent) {
    label = new QLabel("", this);
    label->move(50, 50);

    QTime qtime = QTime::currentTime();
    QString stime = qtime.toString();
    label->setText(stime);

    startTimer(1000);
}


void Timer::timerEvent(QTimerEvent *event) {
    Q_UNUSED(event);

    QTime qtime = QTime::currentTime();
    QString stime = qtime.toString();
    label->setText(stime);
}
