#include <QString>
#include "fraction.h"

void Fraction::set(int nn, int nd) {
    m_numerator = nn;
    m_demoninator = nd;
}

double Fraction::toDouble() const {
    return 1.0 * m_numerator / m_demoninator;
}

QString Fraction::toString() const {
    return QString("%1 / %2").arg(m_numerator).arg(m_demoninator);
}
