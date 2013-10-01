#include <QtCore/QString>
#include <QtGui/QApplication>
#include <QtGui/QMessageBox>
#include <QtGui/QInputDialog>

/* Function prototypes */
double toMPG(int lp100km);
double toLP100KM(int mpg);

/* Constants */
const double LPG = 4.54609188;  // IMPERIAL!
const double KMPM = 1.609344;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QString title = "Fuel Converter";
    QString response;
    double input;
    bool exit = false;
    bool ok = false;

    QMessageBox convMenu(QMessageBox::Question, title, "This program converts fuel "
                         "between Miles-Per-Gallon and Liters-Per-100km.\nPlease choose what to "
                         "convert to: ", QMessageBox::Yes | QMessageBox::No | QMessageBox::Close);
    convMenu.setButtonText(QMessageBox::Yes, "to MPG");
    convMenu.setButtonText(QMessageBox::No, "to lp100km");
    convMenu.setButtonText(QMessageBox::Close, "Quit");

    while (!exit) {
        ok = false;

        switch (convMenu.exec()) {
            case QMessageBox::Yes:
                while (!ok)
                    input = QInputDialog::getDouble(0, title, "Enter Liters-Per-100km value:",
                                                    0, -999, 999, 1, &ok);
                response = QString("%1 lp100km to %2 mpg").arg(input).arg(toMPG(input));
                QMessageBox::information(0, title, response);
                break;

            case QMessageBox::No:
                while (!ok)
                    input = QInputDialog::getDouble(0, title, "Enter Miles-Per-Gallon value:",
                                                    0, -999, 999, 1, &ok);
                response = QString("%1 mpg to %2 lp100km").arg(input).arg(toLP100KM(input));
                QMessageBox::information(0, title, response);
                break;

            case QMessageBox::Close:
                exit = true;
                break;
        }
    }

    return EXIT_SUCCESS;
}

double toMPG(int lp100km) {
    return (100 * LPG) / (KMPM * lp100km);
}

double toLP100KM(int mpg) {
    return (100 * LPG) / (KMPM * mpg);
}
