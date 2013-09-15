#ifndef _STATIC_H_
#define _STATIC_H_

class Thing
{
public:
    Thing(int a, int b);
    ~Thing();

    void display() const;
    static void ShowCount();

private:
    int _first;
    int _second;
    static int Count;
};

#endif
