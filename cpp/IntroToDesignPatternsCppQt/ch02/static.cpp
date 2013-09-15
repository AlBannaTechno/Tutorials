#include "static.h"
#include <iostream>

int Thing::Count = 0;

Thing::Thing(int a, int b)
    : _first(a), _second(b)
{
    ++Count;
}

Thing::~Thing()
{
    --Count;
}

void Thing::display() const
{
    std::cout << _first << "$$" << _second << std::endl;
}

void Thing::ShowCount()
{
    std::cout << "Count = " << Count << std::endl;
}
