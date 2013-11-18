#include "spinbox.h"


SpinBox::SpinBox(QWidget *parent)
    : QWidget(parent) {
    testSpinBox = new QSpinBox(this);
    testSpinBox->setGeometry(50, 50, 60, 30);

    connect(testSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setTitle(int)));
}


void SpinBox::setTitle(int val) {
    setWindowTitle(QString::number(val));
}
