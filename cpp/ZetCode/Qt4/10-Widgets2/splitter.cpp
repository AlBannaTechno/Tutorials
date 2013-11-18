#include <QtGui/QFrame>
#include <QtGui/QSplitter>
#include <QtGui/QHBoxLayout>

#include "splitter.h"


Splitter::Splitter(QWidget *parent)
    : QWidget(parent) {
    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    QFrame *topLeftFrame = new QFrame(this);
    topLeftFrame->setFrameShape(QFrame::StyledPanel);

    QFrame *topRightFrame = new QFrame(this);
    topRightFrame->setFrameShape(QFrame::StyledPanel);

    QSplitter *splitter1 = new QSplitter(Qt::Horizontal, this);
    splitter1->addWidget(topLeftFrame);
    splitter1->addWidget(topRightFrame);

    QFrame *bottomFrame = new QFrame(this);
    bottomFrame->setFrameShape(QFrame::StyledPanel);

    QSplitter *splitter2 = new QSplitter(Qt::Vertical, this);
    splitter2->addWidget(splitter1);
    splitter2->addWidget(bottomFrame);

    mainLayout->addWidget(splitter2);
    setLayout(mainLayout);
}
