#include "firstprograms.h"
#include <QtGui/QApplication>
#include <QtGui/QWidget>
#include <QtGui/QPushButton>


class MyButton : public QWidget {
    public:
        MyButton(QWidget *parent=0);
};


MyButton::MyButton(QWidget *parent) : QWidget(parent) {
    QPushButton *quit = new QPushButton("Quit", this);
    quit->setGeometry(50, 40, 75, 30);
    
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}


int button(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyButton window;
    
    window.resize(250, 150);
    window.move(300, 300);
    window.setWindowTitle("Button");
    window.show();
    
    return app.exec();
}