#include "position.h"
#include <sstream>

Position::Position(std::string name, std::string description)
    : _name(name), _description(description)
{ }

std::string Position::toString() const
{
    std::ostringstream os;

    os << _name << ":\n"
       << _description << ".";

    return os.str();
}

Position &Position::operator=(const Position &other)
{
    if (this == &other)
        return *this;

    _name = other._name;
    _description = other._description;

    return *this;
}

std::string Position::get_name() const
{
    return _name;
}

std::string Position::get_description() const
{
    return _description;
}
