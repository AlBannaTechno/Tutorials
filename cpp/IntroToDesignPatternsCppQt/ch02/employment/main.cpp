#include "person.h"
#include <iostream>

int main()
{
    Employer starfleet("Starfleet Federation", "Space Exploration");
    Employer borg("Borg", "Total Domination");

    Person person1("Jean-Luc Picard");
    Person person2("Wesley Crusher");

    Position starfleet_captain("Starfleet Captain", "Captain of the Ship!");
    Position starfleet_driver("Driver", "Drives the Ship");
    Position borg_overmind("Borg Overmind", "Ruler of the Borg");

    std::cout << person1.toString() << std::endl;
    std::cout << person2.toString() << std::endl;
    std::cout << starfleet.toString() << std::endl;
    std::cout << borg.toString() << std::endl;
    std::cout << starfleet_captain.toString() << std::endl;
    std::cout << starfleet_driver.toString() << std::endl;
    std::cout << borg_overmind.toString() << "\n\n";

    std::cout << person1.get_name() << " currently works for: "
              << person1.get_employer().get_name() << "\n\n";

    starfleet.hire(person1, starfleet_captain);
    starfleet.hire(person2, starfleet_driver);
    std::cout << "Welcome to " << person1.get_employer().get_name() << "!\n"
              << "We've hired: " << person1.get_name() << " and " << person2.get_name() << "\n\n";

    borg.hire(person1, borg_overmind);
    std::cout << "OH NO! The borg have captured " << person1.get_name() << "!\n"
              << "He's now the " << person1.get_position().get_name() << "!\n";

    return 0;
}
