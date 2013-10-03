#include "position.h"

Position::Position(QString name, QString description)
    : m_Name(name), m_Description(description) { }

QString Position::toString() const {
    return QString("%1:\n%2.").arg(m_Name).arg(m_Description);
}

QString Position::getName() const {
    return m_Name;
}

QString Position::getDescription() const {
    return m_Description;
}

Position &Position::operator=(const Position &other) {
    if (this == &other)
        return *this;

    m_Name = other.m_Name;
    m_Description = other.m_Description;

    return *this;
}
