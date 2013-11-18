#ifndef LABEL_H
#define LABEL_H

#include <QtGui/QWidget>
#include <QtGui/QLabel>


class Label : public QWidget {
    QLabel *label;

public:
    Label(QWidget *parent=0);
};

#endif // LABEL_H
