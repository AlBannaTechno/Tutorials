#include "thing.h"

void function(Thing t);

int main() {
    Thing t1(101), t2(102);
    Thing *p_t1 = new Thing(103);

    function(t1);
    {
        Thing t3(104);
        Thing p_t = new Thing(105);
    }

    delete tp1;

    return 0;
}

void function(Thing t) {
    Thing lt(106);
    Thing *p_t1 = new Thing(107);
    Thing *p_t2 = new Thing(108);
}
