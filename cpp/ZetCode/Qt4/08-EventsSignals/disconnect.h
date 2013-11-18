#ifndef DISCONNECT_H
#define DISCONNECT_H

#include <QtGui/QWidget>
#include <QtGui/QPushButton>


class Disconnect : public QWidget {
    Q_OBJECT

    QPushButton *clickButton;

public:
    Disconnect(QWidget *parent=0);

private slots:
    void onClick();
    void onCheck(int state);
};

#endif // DISCONNECT_H
