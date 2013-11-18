#include <QtGui/QApplication>

#include "checkbox.h"
#include "listwidget.h"
#include "pixmap.h"
#include "splitter.h"
#include "table.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

//    CheckBox window;
//    ListWidget window;
//    Pixmap window;
//    Splitter window;
    Table window;

    window.resize(250, 150);
    window.move(300, 300);
    window.setWindowTitle("Widgets 2");
    window.show();

    return app.exec();
}
