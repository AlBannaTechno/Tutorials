#include <QtGui/QPushButton>
#include <QtGui/QGridLayout>
#include "calculator.h"


Calculator::Calculator(QWidget *parent)
    : QWidget(parent) {
    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->setSpacing(2);

    QString values[16] = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", ".", "=", "+"
    };

    int pos = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            QPushButton *button = new QPushButton(values[pos], this);
            button->setFixedSize(40, 40);
            mainLayout->addWidget(button, i, j);
            ++pos;
        }
    }

    setLayout(mainLayout);
}
