#include <QtGui/QApplication>

#include "click.h"
#include "keypress.h"
#include "move.h"
#include "disconnect.h"
#include "timer.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

//    Click window;
//    KeyPress window;
//    Move window;
//    Disconnect window;
    Timer window;

    window.move(300, 300);
    window.resize(250, 150);
    window.setWindowTitle("Click");
    window.show();

    return app.exec();
}
