#include "person.h"

Person::Person(QString name)
    : m_Name(name), m_Employed(false), m_Employer("None", "N/A"), m_Position("None", "N/A") { }

bool Person::apply(Position *newPosition) {

}

void Person::newPosition(const Employer &newEmployer, const Position &newPosition) {
    m_Employer = newEmployer;
    m_Position = newPosition;
    m_Employed = true;
}

QString Person::toString() const {
    QString desc;

    desc.append(m_Name);
    if (m_Employed)
        desc.append(QString(" is currently employed by %1, working in %2.")
                    .arg(m_Employer.getName()).arg(m_Position.getName()));
    else
        desc.append(" is not employed.");

    return desc;
}

QString Person::getName() const {
    return m_Name;
}

Employer Person::getEmployer() const {
    if (m_Employed)
        return m_Employer;
    else
        return Employer("Etna", "Overlord Beauty Queen");
}

Position Person::getPosition() const {
    if (m_Employed)
        return m_Position;
    else
        return Position("Prinny", "Under payed, over worked, expendable slave");
}

Person &Person::operator=(const Person &other) {
    if (this == &other)
        return *this;

    m_Name = other.m_Name;
    m_Employed = other.m_Employed;
    m_Employer = other.m_Employer;
    m_Position = other.m_Position;

    return *this;
}
