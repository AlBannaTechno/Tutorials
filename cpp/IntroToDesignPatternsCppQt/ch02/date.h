#ifndef _DATE_H_
#define _DATE_H_

#include <string>

class Date {
public:
    Date();
    Date(int year, int month, int day);

    void set(int year, int month, int day);
    void setToToday();
    Date addDays(int days);

    std::string getWeekDay() const;
    std::string toString(bool brief) const;

    bool operator==(const Date &lhs, const Date &rhs) const;
    bool operator<(const Date &lhs, const Date &rhs) const;

    static bool leapYear(int year) const;
    static std::string monthName(int month) const;
    static int yearDays(int year) const;
    static int monthDays(int month, int year) const;

private:
    int days_since_base_date;

    void getYMD(int &year, int &month, int &day);

    static int ymd2dsbd(int year, int month, int day);
};

#endif _DATE_H_
