#include "slider.h"


Slider::Slider(QWidget *parent)
    : QWidget(parent) {
    testSlider = new QSlider(Qt::Horizontal, this);
    testSlider->setGeometry(50, 50, 130, 30);

    testLabel = new QLabel("0", this);
    testLabel->setGeometry(230, 50, 20, 30);

    connect(testSlider, SIGNAL(valueChanged(int)), testLabel, SLOT(setNum(int)));
}
