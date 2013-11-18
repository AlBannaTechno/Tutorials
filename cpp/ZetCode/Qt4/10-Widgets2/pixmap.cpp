#include <QtGui/QPixmap>
#include <QtGui/QLabel>
#include <QtGui/QHBoxLayout>

#include "pixmap.h"


Pixmap::Pixmap(QWidget *parent)
    : QWidget(parent) {
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    QPixmap pixmap("bojnice.jpg");

    QLabel *mainLabel = new QLabel(this);
    mainLabel->setPixmap(pixmap);

    mainLayout->addWidget(mainLabel);
    setLayout(mainLayout);
}
