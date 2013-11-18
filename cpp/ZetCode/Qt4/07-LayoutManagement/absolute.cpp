#include "absolute.h"
#include <QtGui/QTextEdit>


Absolute::Absolute(QWidget *parent)
    : QWidget(parent) {
    QTextEdit *mainTextEdit = new QTextEdit(this);
    mainTextEdit->setGeometry(5, 5, 200, 150);
}
