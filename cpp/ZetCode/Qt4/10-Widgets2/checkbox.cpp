#include <QtGui/QCheckBox>

#include "checkbox.h"


CheckBox::CheckBox(QWidget *parent)
    : QWidget(parent) {
    QCheckBox *testCheckBox = new QCheckBox("Show Title", this);
    testCheckBox->setCheckState(Qt::Checked);
    testCheckBox->move(50, 50);

    connect(testCheckBox, SIGNAL(stateChanged(int)), this, SLOT(showTitle(int)));
}

void CheckBox::showTitle(int state) {
    if (state == Qt::Checked)
        setWindowTitle("QCheckBox");
    else
        setWindowTitle("");
}
