#include "toolbar.h"
#include <QtGui/QToolBar>
#include <QtGui/QIcon>
#include <QtGui/QAction>


Toolbar::Toolbar(QWidget *parent)
    : QMainWindow(parent) {
    QPixmap newIcon(":/icons/new.png");
    QPixmap openIcon(":/icons/open.png");
    QPixmap quitIcon(":/icons/quit.png");

    QToolBar *toolbar = addToolBar("Main Toolbar");
    toolbar->addAction(QIcon(newIcon), "New File");
    toolbar->addAction(QIcon(openIcon), "Open File");
    toolbar->addSeparator();
    QAction *quit = toolbar->addAction(QIcon(quitIcon), "Quit Application");

    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
}
