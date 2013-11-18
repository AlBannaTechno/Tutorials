#include <QtCore/QTextStream>
#include <QtGui/QCheckBox>

#include "disconnect.h"


Disconnect::Disconnect(QWidget *parent)
    : QWidget(parent) {
    clickButton = new QPushButton("Click", this);
    clickButton->setGeometry(50, 40, 75, 30);

    QCheckBox *testCheckBox = new QCheckBox("Connect", this);
    testCheckBox->setCheckState(Qt::Checked);
    testCheckBox->move(150, 40);

    connect(clickButton, SIGNAL(clicked()), this, SLOT(onClick()));
    connect(testCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onCheck(int)));
}


void Disconnect::onClick() {
    QTextStream out(stdout);
    out << "Button clicked" << endl;
}


void Disconnect::onCheck(int state) {
    if (state == Qt::Checked)
        connect(clickButton, SIGNAL(clicked()), this, SLOT(onClick()));
    else
        clickButton->disconnect(SIGNAL(clicked()));
}
