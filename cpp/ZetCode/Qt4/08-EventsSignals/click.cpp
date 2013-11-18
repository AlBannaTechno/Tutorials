#include <QtGui/QPushButton>
#include <QtGui/QApplication>

#include "click.h"


Click::Click(QWidget *parent)
    : QWidget(parent) {
    QPushButton *quitButton = new QPushButton("Quit", this);
    quitButton->setGeometry(50, 40, 75, 30);

    connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
}
