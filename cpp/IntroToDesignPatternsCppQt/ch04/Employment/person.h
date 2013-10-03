#ifndef PERSON_H
#define PERSON_H

#include "employer.h"
#include "position.h"
#include <QtCore/QString>

class Person {
public:
    Person(QString name);

    bool apply(Position *newPosition);
    void newPosition(const Employer &newEmployer, const Position &newPosition);
    QString toString() const;

    QString getName() const;
    Employer getEmployer() const;
    Position getPosition() const;

    Person &operator=(const Person &other);

private:
    QString m_Name;
    bool m_Employed;
    Position m_Position;
    Employer m_Employer;
};

#endif // PERSON_H
