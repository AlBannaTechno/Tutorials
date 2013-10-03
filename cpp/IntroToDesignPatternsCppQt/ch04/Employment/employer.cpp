#include <QtCore/QTime>
#include "employer.h"
#include "person.h"
#include "position.h"

Employer::Employer(QString name, QString market)
    :m_Name(name), m_Market(market) { }

bool Employer::hire(Person &newHire, Position &newPosition) {
    /* Return false 50% of the time. Don't forget to set the seed! */
    qsrand(QTime::currentTime().msec());
    if (qrand() % 2)
        return false;

    newHire.newPosition(*this, newPosition);

    return true;
}

QString Employer::toString() const {
    return QString("%1 in %2.").arg(m_Name).arg(m_Market);
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
