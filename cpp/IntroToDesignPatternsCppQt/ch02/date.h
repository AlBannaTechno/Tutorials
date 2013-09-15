#ifndef _DATE_H_
#define _DATE_H_

#include <string>

class Date
{
    Date();
    Date(int year, int month, int day);

    std::string toString(bool brief);
    void setToToday();
};

#endif
