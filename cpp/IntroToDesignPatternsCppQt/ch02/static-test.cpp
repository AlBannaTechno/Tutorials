#include "static.h"

int main()
{
    Thing::ShowCount();

    Thing t1(3, 4);
    Thing t2(5, 6);

    t1.ShowCount();

    {
        Thing t3(7, 8);
        Thing t4(9, 10);

        Thing::ShowCount();
    }

    Thing::ShowCount();

    return 0;
}
