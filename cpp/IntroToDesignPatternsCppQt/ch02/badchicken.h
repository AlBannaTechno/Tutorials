// an example of what NOT to do, this is called a circular dependency
#ifndef _BADCHICKEN_H_
#define _BADCHICKEN_H_

#include "badegg.h"

class Chicken
{
public:
    Egg *layEgg();
};

#endif
