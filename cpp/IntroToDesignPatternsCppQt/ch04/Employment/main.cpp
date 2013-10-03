#include <QtCore/QCoreApplication>
#include <QtCore/QTextStream>
#include "person.h"

/* Qt versions of iostream prints */
QTextStream cout(stdout);

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    Employer employer1("Starfleet Federation", "Space Exploration");
    Employer employer2("Borg", "Total Domination");

    Person person1("Jean-Luc Picard");
    Person person2("Wesley Crusher");

    Position position1("Starfleet Captian", "Captain of the Ship!");
    Position position2("Driver", "Drives the Ship");
    Position position3("Borg Overmind", "Ruler of the Borg");

    cout << person1.toString() << endl;
    cout << person2.toString() << endl;
    cout << employer1.toString() << endl;
    cout << employer2.toString() << endl;
    cout << position1.toString() << endl;
    cout << position2.toString() << endl;
    cout << position3.toString() << endl;

    cout << person1.getName() << " currently works for: "
         << person1.getEmployer().getName() << "\n\n";

    employer1.hire(person1, position1);
    employer1.hire(person2, position2);
    cout << "Welcome to " << person1.getEmployer().getName() << "!\n"
         << "We've hired: " << person1.getName() << " and " << person2.getName() << "\n\n";

    employer2.hire(person1, position3);
    cout << "OH NO! The borg have captured " << person1.getName() << "!\n"
         << "He is now the " << person1.getPosition().getName() << "!\n";

    return EXIT_SUCCESS;
}
