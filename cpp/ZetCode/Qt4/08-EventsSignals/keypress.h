#ifndef KEYPRESS_H
#define KEYPRESS_H

#include <QtGui/QWidget>


class KeyPress : public QWidget {
public:
    KeyPress(QWidget *parent=0);

private:
    void keyPressEvent(QKeyEvent *event);
};

#endif // KEYPRESS_H
