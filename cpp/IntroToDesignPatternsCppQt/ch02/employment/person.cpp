#include "person.h"
#include <sstream>

Person::Person(std::string name)
    : _name(name), _employed(false), _employer("None", "N/A"), _position("None", "N/A")
{ }

void Person::newPosition(Employer new_employer, Position new_position)
{
    _employer = new_employer;
    _position = new_position;
    _employed = true;
}

std::string Person::toString() const
{
    std::ostringstream os;

    os << _name;
    if (_employed)
        os << " is currently employed by " << _employer.get_name()
           << ", working in " << _position.get_name() << ".";
    else
        os << " is not currently employed.";

    return os.str();
}

Person &Person::operator=(const Person &other)
{
    if (this == &other)
        return *this;

    _name = other._name;
    _employed = other._employed;
    _employer = other._employer;
    _position = other._position;

    return *this;
}

std::string Person::get_name() const
{
    return _name;
}

Employer Person::get_employer() const
{
    if (_employed)
        return _employer;
    else
        return Employer("Etna", "Overlord Beauty Queen");
}

Position Person::get_position() const
{
    if (_employed)
        return _position;
    else
        return Position("Prinny", "Under payed, over worked, expendable slave");
}
