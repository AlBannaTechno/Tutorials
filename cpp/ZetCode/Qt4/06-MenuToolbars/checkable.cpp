#include "checkable.h"
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>


Checkable::Checkable(QWidget *parent)
    : QMainWindow(parent) {
    viewAction = new QAction("&View Statusbar", this);
    viewAction->setCheckable(true);
    viewAction->setChecked(true);

    QMenu *file;
    file = menuBar()->addMenu("&File");
    file->addAction(viewAction);

    statusBar();

    connect(viewAction, SIGNAL(triggered()), this, SLOT(toggleStatusbar()));
}


void Checkable::toggleStatusbar() {
    if (viewAction->isChecked())
        statusBar()->show();
    else
        statusBar()->hide();
}
