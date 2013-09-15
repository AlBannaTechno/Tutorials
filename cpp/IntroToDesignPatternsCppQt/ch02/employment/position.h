#ifndef _POSITION_H_
#define _POSITION_H_

#include <string>

class Position
{
public:
    Position(std::string name, std::string description);

    std::string toString() const;

    Position &operator=(const Position &other);

    std::string get_name() const;
    std::string get_description() const;

private:
    std::string _name;
    std::string _description;
};

#endif
