#ifndef _EMPLOYER_H_
#define _EMPLOYER_H_

#include <string>

class Person;
class Position;

class Employer
{
public:
    Employer(std::string name, std::string market);

    bool hire(Person &new_hire, Position &new_position);
    std::string toString() const;

    Employer &operator=(const Employer &other);

    std::string get_name() const;
    std::string get_market() const;

private:
    std::string _name;
    std::string _market;
};

#endif
