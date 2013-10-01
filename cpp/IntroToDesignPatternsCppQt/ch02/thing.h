#ifndef _THING_H_
#define _THING_H_

#include <iostream>
#include <string>

class Thing {
public:
    Thing(int n) : m_num(n) { }
    ~Thing() { std::cout << "destructor called: " << m_num << endl; }

private:
    std::string m_string;
    int m_num;
};

#endif
