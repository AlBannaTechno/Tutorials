#ifndef TIMER_H
#define TIMER_H

#include <QtGui/QWidget>
#include <QtGui/QLabel>


class Timer : public QWidget {
    QLabel *label;

public:
    Timer(QWidget *parent=0);

protected:
    void timerEvent(QTimerEvent *event);
};

#endif // TIMER_H
