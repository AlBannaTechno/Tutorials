#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QtGui/QWidget>


class CheckBox : public QWidget {
    Q_OBJECT

public:
    CheckBox(QWidget *parent=0);

private slots:
    void showTitle(int state);
};

#endif // CHECKBOX_H
