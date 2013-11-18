#include "firstprograms.h"
#include <QtGui/QApplication>
#include <QtGui/QDesktopWidget>
#include <QtGui/QWidget>


int center(int argc, char *argv[]) {
    const int WIDTH = 250;
    const int HEIGHT = 150;
    
    int screenWidth;
    int screenHeight;
    int x;
    int y;
    
    QApplication app(argc, argv);
    QWidget window;
    QDesktopWidget *desktop = QApplication::desktop();
    
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    
    x = (screenWidth - WIDTH) / 2;
    y = (screenHeight - HEIGHT) / 2;
    
    window.resize(WIDTH, HEIGHT);
    window.move(x, y);
    window.setWindowTitle("Center");
    window.show();
    
    return app.exec();
}
