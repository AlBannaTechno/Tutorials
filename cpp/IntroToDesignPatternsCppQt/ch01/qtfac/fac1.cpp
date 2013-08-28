#include <QtGui>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QTextStream cout(stdout);

    int answer = 0;

    do {
        int fact_arg = 0;
        int fact = 1;
        bool ok;

        fact_arg = QInputDialog::getInt(0, "Factorial Calculator", "Factorial of:", 0, 0, 9999, 1,
                                        &ok);
        cout << "User entered: " << fact_arg << endl;

        if (!ok)
            break;

        int i = 2;
        while (i <= fact_arg) {
            fact *= i;
            ++i;
        }

        QString response = QString("The factorial of %1 is %2.\n%3")
                            .arg(fact_arg)
                            .arg(fact)
                            .arg("Do you want to compute another factorial?");
        answer = QMessageBox::question(0, "Play again?", response,
                                        QMessageBox::Yes | QMessageBox::No);
    }
    while (answer == QMessageBox::Yes);

    return EXIT_SUCCESS;
}
