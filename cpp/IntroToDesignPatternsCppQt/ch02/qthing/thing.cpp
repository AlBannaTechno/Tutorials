#include <QtCore/QTextStream>
#include "thing.h"

void Thing::set(int num, char c)
{
    _number = num;
    _character = c;
}

void Thing::increment()
{
    ++_number;
    ++_character;
}

void Thing::show()
{
    QTextStream cout(stdout);
    cout << _number << '\t' << _character << endl;
}

int Thing::get_number()
{
    return _number;
}

char Thing::get_character()
{
    return _character;
}
