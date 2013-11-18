#include "firstprograms.h"
#include <QtGui/QApplication>
#include <QtGui/QWidget>
#include <QtGui/QIcon>


int icon(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    
    window.resize(250, 150);
    window.move(300, 300);
    window.setWindowTitle("Icon");
    window.setWindowIcon(QIcon("globe-network.png"));
    window.show();
    
    return app.exec();
}
