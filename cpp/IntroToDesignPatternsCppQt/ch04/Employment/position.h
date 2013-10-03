#ifndef POSITION_H
#define POSITION_H

#include <QtCore/QString>

class Position {
public:
    Position(QString name, QString description);

    QString toString() const;

    QString getName() const;
    QString getDescription() const;

    Position &operator=(const Position &other);

private:
    QString m_Name;
    QString m_Description;
};

#endif // POSITION_H
