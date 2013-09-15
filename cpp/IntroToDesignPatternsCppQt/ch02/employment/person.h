#ifndef _PERSON_H_
#define _PERSON_H_

#include "employer.h"
#include "position.h"
#include <string>

class Person
{
public:
    Person(std::string name);

    void newPosition(Employer new_employer, Position new_position);
    std::string toString() const;

    Person &operator=(const Person &other);

    std::string get_name() const;
    Employer get_employer() const;
    Position get_position() const;

private:
    std::string _name;
    bool _employed;
    Position _position;
    Employer _employer;
};

#endif
