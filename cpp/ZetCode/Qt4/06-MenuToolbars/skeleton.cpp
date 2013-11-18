#include "skeleton.h"
#include <QtGui/QToolBar>
#include <QtGui/QIcon>
#include <QtGui/QAction>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>


Skeleton::Skeleton(QWidget *parent)
    : QMainWindow(parent) {
    QPixmap newIcon(":/icons/new.png");
    QPixmap openIcon(":/icons/open.png");
    QPixmap quitIcon(":/icons/quit.png");

    QAction *quitAction = new QAction("&Quit", this);

    QMenu *file = menuBar()->addMenu("&File");
    file->addAction(quitAction);

    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    QToolBar *toolbar = addToolBar("Main Toolbar");
    toolbar->addAction(QIcon(newIcon), "New File");
    toolbar->addAction(QIcon(openIcon), "Open File");
    toolbar->addSeparator();
    QAction *quitAction2 = toolbar->addAction(QIcon(quitIcon), "Quit Application");
    connect(quitAction2, SIGNAL(triggered()), qApp, SLOT(quit()));

    QTextEdit *mainTextEdit = new QTextEdit(this);
    setCentralWidget(mainTextEdit);

    statusBar()->showMessage("Ready");
}
