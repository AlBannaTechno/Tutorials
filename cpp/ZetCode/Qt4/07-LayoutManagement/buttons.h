#ifndef BUTTONS_H
#define BUTTONS_H

#include <QtGui/QWidget>
#include <QtGui/QPushButton>


class Buttons : public QWidget {
    Q_OBJECT

    QPushButton *okButton;
    QPushButton *applyButton;

public:
    Buttons(QWidget *parent=0);
};

#endif  // BUTTONS_H
