#include "firstprograms.h"
#include "communicate.h"


int main(int argc, char *argv[]) {
//    return simple(argc, argv);
//    return center(argc, argv);
//    return tooltip(argc, argv);
//    return icon(argc, argv);
//    return cursor(argc, argv);
//    return button(argc, argv);
    QApplication app(argc, argv);
    Communicate window;
    
    window.setWindowTitle("Communicate");
    window.show();
    
    return app.exec();
}
