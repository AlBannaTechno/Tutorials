#include <QtGui/QApplication>

#include "label.h"
#include "slider.h"
#include "spinbox.h"
#include "ledit.h"
#include "statusbar.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

//    Label window;
//    Slider window;
//    SpinBox window;
//    Ledit window;
    Statusbar window;

    window.move(300, 300);
    window.setWindowTitle("Widgets");
    window.show();

    return app.exec();
}
