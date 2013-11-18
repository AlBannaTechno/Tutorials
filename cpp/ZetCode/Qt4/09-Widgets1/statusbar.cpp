#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QFrame>
#include <QtGui/QStatusBar>

#include "statusbar.h"


Statusbar::Statusbar(QWidget *parent)
    : QMainWindow(parent) {
    QFrame *mainFrame = new QFrame(this);
    setCentralWidget(mainFrame);

    okButton = new QPushButton("OK", mainFrame);
    okButton->move(20, 50);

    applyButton = new QPushButton("Apply", mainFrame);
    applyButton->move(120, 50);

    statusBar();

    connect(okButton, SIGNAL(clicked()), this, SLOT(OnOkPressed()));
    connect(applyButton, SIGNAL(clicked()), this, SLOT(OnApplyPressed()));
}

void Statusbar::OnOkPressed() {
    statusBar()->showMessage("OK button pressed");
}

void Statusbar::OnApplyPressed() {
    statusBar()->showMessage("Apply button pressed");
}
