#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include <QString>
#include <QTextStream>

double to_celsius(double f);
double to_fahrenheit(double c);

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QTextStream cout(stdout);
    QString response;

    QMessageBox temp_menu(QMessageBox::Question, "Temperature Converter",
                          "Welcome to the Temperature Converter program."
                          "\nPlease select a temperature conversion:",
                          QMessageBox::Yes | QMessageBox::No | QMessageBox::Close);
    temp_menu.setButtonText(QMessageBox::Yes, "C to F");
    temp_menu.setButtonText(QMessageBox::No, "F to C");
    temp_menu.setButtonText(QMessageBox::Close, "Exit");

    bool exit = false, ok = false;
    double temp_arg = 0;

    while (!exit) {
        ok = false;
        switch (temp_menu.exec()) {
            case QMessageBox::Yes:
                while (!ok)
                    temp_arg = QInputDialog::getDouble(0, "Temperature Converter",
                                                       "Enter a Celsius value:",
                                                       0, -999, 999, 1, &ok);
                response = QString("%1 C is %2 F").arg(temp_arg).arg(to_fahrenheit(temp_arg));
                QMessageBox::information(0, "Temperature Converter", response);
                break;

            case QMessageBox::No:
                while (!ok)
                    temp_arg = QInputDialog::getDouble(0, "Temperature Converter",
                                                       "Enter a Fahrenheit value:",
                                                       0, -999, 999, 1, &ok);
                response = QString("%1 F is %2 C").arg(temp_arg).arg(to_celsius(temp_arg));
                QMessageBox::information(0, "Temperature Converter", response);
                break;

            case QMessageBox::Close:
                exit = true;
                break;
        }
    }

    cout << fixed << qSetRealNumberPrecision(2);
    for (int i = 0; i <= 100; i += 5) {
        cout << i << " F\t= " << to_celsius(i) << " C" << endl;
    }

    return EXIT_SUCCESS;
}

double to_celsius(double f) {
    return ((f - 32) * 5 / 9);
}

double to_fahrenheit(double c) {
    return (c * 9 / 5 + 32);
}
