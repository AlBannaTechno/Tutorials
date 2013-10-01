#ifndef PERSON_H
#define PERSON_H

#include "employer.h"
#include "position.h"
#include <QtCore/QString>

class Person {
public:
    Person(QString name);

    void newPosition(Employer newEmployer, Position newPosition);
    QString toString() const;

    QString getName() const;
    Employer getEmployer() const;
    Position getPosition() const;

private:
    QString m_Name;
    bool m_Employed;
    Position m_Position;
    Employer m_Employer;
};

#endif // PERSON_H
