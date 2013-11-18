#include "simplemenu.h"
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>


SimpleMenu::SimpleMenu(QWidget *parent)
    : QMainWindow(parent) {
    QAction *quit = new QAction("&Quit", this);

    QMenu *file;
    file = menuBar()->addMenu("&File");
    file->addAction(quit);

    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
}
