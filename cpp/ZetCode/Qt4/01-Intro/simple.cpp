#include <QtGui/QApplication>
#include <QtGui/QWidget>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;

    window.resize(250, 150);
    window.setWindowTitle("Simple Example");
    window.show();

    return app.exec();
}
