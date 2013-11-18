#include "buttons.h"
#include <QtGui/QVBoxLayout>
#include <QtGui/QHBoxLayout>


Buttons::Buttons(QWidget *parent)
    : QWidget(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    okButton = new QPushButton("OK", this);
    applyButton = new QPushButton("Apply", this);

    buttonLayout->addWidget(okButton, 1, Qt::AlignRight);
    buttonLayout->addWidget(applyButton, 0, Qt::AlignRight);

    mainLayout->addStretch(1);
    mainLayout->addLayout(buttonLayout);
}
