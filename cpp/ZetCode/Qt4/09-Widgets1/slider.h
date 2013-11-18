#ifndef SLIDER_H
#define SLIDER_H

#include <QtGui/QWidget>
#include <QtGui/QSlider>
#include <QtGui/QLabel>


class Slider : public QWidget {
    Q_OBJECT

    QSlider *testSlider;
    QLabel *testLabel;

public:
    Slider(QWidget *parent=0);
};

#endif // SLIDER_H
