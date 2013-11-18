#ifndef SPINBOX_H
#define SPINBOX_H

#include <QtGui/QWidget>
#include <QtGui/QSpinBox>


class SpinBox : public QWidget {
    Q_OBJECT

    QSpinBox *testSpinBox;

public:
    SpinBox(QWidget *parent=0);

private slots:
    void setTitle(int val);
};

#endif // SPINBOX_H
