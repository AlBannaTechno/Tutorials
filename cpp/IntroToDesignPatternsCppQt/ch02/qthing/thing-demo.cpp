#include <QtCore/QTextStream>
#include "thing.h"

void display(Thing t, int n);

int main()
{
    QTextStream cout(stdout);
    Thing t1;
    Thing t2;

    t1.set(23, 'H');
    t2.set(1234, 'w');
    t1.increment();
//  cout << t1._number;  // this won't compile because _number is a private variable
    display(t1, 3);
//  cout << i << endl;  // this won't compile because i doesn't exist in this scope

    return 0;
}

void display(Thing t, int n)
{
    for (int i = 0; i < n; ++i)
        t.show();
}
