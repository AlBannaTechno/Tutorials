#include "employer.h"
#include "person.h"
#include "position.h"
#include <sstream>

Employer::Employer(std::string name, std::string market)
    : _name(name), _market(market)
{ }

bool Employer::hire(Person &new_hire, Position &new_position)
{
    new_hire.newPosition(*this, new_position);

    return true;
}

std::string Employer::toString() const
{
    std::ostringstream os;

    os << _name << " in " << _market << ".";

    return os.str();
}

Employer &Employer::operator=(const Employer &other)
{
    if (this == &other)
        return *this;

    _name = other._name;
    _market = other._market;

    return *this;
}

std::string Employer::get_name() const
{
    return _name;
}

std::string Employer::get_market() const
{
    return _market;
}
