#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QtGui/QMainWindow>
#include <QtGui/QApplication>


class Toolbar : public QMainWindow {
    Q_OBJECT

public:
    Toolbar(QWidget *parent=0);
};

#endif // TOOLBAR_H
