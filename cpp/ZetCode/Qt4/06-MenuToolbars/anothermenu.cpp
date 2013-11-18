#include "anothermenu.h"
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>


AnotherMenu::AnotherMenu(QWidget *parent)
    : QMainWindow(parent) {
    QPixmap newIcon(":/icons/new.png");
    QPixmap openIcon(":/icons/open.png");
    QPixmap quitIcon(":/icons/quit.png");

    QAction *newAction = new QAction(newIcon, "&New", this);
    QAction *openAction = new QAction(openIcon, "&Open", this);
    QAction *quitAction = new QAction(quitIcon, "&Quit", this);
    quitAction->setShortcut(tr("CTRL+Q"));

    QMenu *fileMenu;
    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);

    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
}
