#include "absolute.h"
#include "verticalbox.h"
#include "buttons.h"
#include "layouts.h"
#include "calculator.h"
#include "karenina.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

//    Absolute window;
//    VerticalBox window;
//    Buttons window;
//    Layouts window;
//    Calculator window;
    Karenina window;

    window.move(300, 300);
    window.setWindowTitle("Layout Management");
    window.show();

    return app.exec();
}
