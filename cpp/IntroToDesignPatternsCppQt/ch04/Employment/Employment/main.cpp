#include <QtCore/QCoreApplication>
#include <QtCore/QTextStream>
#include "person.h"

/* Qt stream replacements */
QTextStream cout(stdout);

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    Employer starfleet("Starfleet Federation", "Space Exploration");
    Employer borg("Borg", "Total Domination");

    Person person1("Jean-Luc Picard");
    Person person2("Wesley Crusher");

    Position starfleetCaptain("Starfleet Captain", "Captain of the Ship!");
    Position starfleetDriver("Driver", "Drives the Ship");
    Position borgOvermind("Borg Overmind", "Ruler of the Borg");

    cout << person1.toString() << endl;
    cout << person2.toString() << endl;
    cout << starfleet.toString() << endl;
    cout << borg.toString() << endl;
    cout << starfleetCaptain.toString() << endl;
    cout << starfleetDriver.toString() << endl;
    cout << borgOvermind.toString() << endl;

    cout << person1.getName() << " currently works for "
         << person1.getEmployer().getName() << "\n\n";

    starfleet.hire(person1, starfleetCaptain);
    starfleet.hire(person2, starfleetDriver);
    cout << "Welcome to " << person1.getEmployer().getName() << "!\n"
         << "We've hired: " << person1.getName() << " and " << person2.getName() << "\n\n";

    borg.hire(person1, borgOvermind);
    cout << "OH NO! The borg have captured " << person1.getName() << "!\n"
         << "He's now the " << person1.getPosition().getName() << "!\n";

    return EXIT_SUCCESS;
}
