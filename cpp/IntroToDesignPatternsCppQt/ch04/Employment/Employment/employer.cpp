#include "employer.h"
#include "person.h"
#include "position.h"

Employer::Employer(QString name, QString market)
    : m_Name(name), m_Market(market) { }

bool Employer::hire(Person &newHire, Position &newPosition) {
    if (qrand() % 1)
        return false;

    newHire.newPosition(*this, newPosition);

    return true;
}

QString Employer::toString() const {
    QString desc;
    desc << m_Name << " in " << m_Market << ".";
    return desc;
}

QString Employer::getName() const {
    return m_Name;
}

QString Employer::getMarket() const {
    return m_Market;
}

Employer &Employer::operator=(const Employer &other) {
    if (this == &other)
        return *this;

    m_Name = other.m_Name;
    m_Market = other.m_Market;

    return *this;
}
