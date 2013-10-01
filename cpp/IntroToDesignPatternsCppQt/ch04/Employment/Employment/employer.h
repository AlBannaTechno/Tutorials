#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <QtCore/QString>

class Person;
class Position;

class Employer {
public:
    Employer(QString name, QString market);

    bool hire(Person &newHire, Position &newPosition);
    QString toString() const;

    QString getName() const;
    QString getMarket() const;

    Employer &operator=(const Employer &other);

private:
    QString m_Name;
    QString m_Market;
};

#endif // EMPLOYER_H
