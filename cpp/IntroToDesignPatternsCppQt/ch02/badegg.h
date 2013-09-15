// an example of what NOT to do, this is called a circular dependency
#ifndef _BADEGG_H_
#define _BADEGG_H_

#include "badchicken.h"

class Egg
{
public:
    Chicken *getParent();
};

#endif
