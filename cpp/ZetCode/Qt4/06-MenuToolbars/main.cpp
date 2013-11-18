#include "simplemenu.h"
#include "anothermenu.h"
#include "checkable.h"
#include "toolbar.h"
#include "skeleton.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

//    SimpleMenu window;
//    AnotherMenu window;
//    Checkable window;
//    Toolbar window;
    Skeleton window;

    window.resize(350, 250);
    window.move(300, 300);
    window.setWindowTitle("Simple Menu");
    window.show();

    return app.exec();
}
