#include <QTextStream>
#include <QString>

int main() {
    const char *char_str = "This is one very long string "
                           "so I will continue it on the next line";
    QTextStream cout(stdout);
    QString str = char_str;

    cout << str << endl;
    cout << "\nA\tb\\c\'d\"" << endl;

    cout << "GNU stands for \"GNU's Not UNIX\"\n";
    cout << "\tTitle 1\t\t\"Cat Clothing\"\n"
         << "\tTitle 2\t\t\"Dog Dancing\"\n";

    return 0;
}
