#ifndef _THING_H_
#define _THING_H_

class Thing
{
public:
    void set(int num, char c);
    void increment();
    void show();
    int get_number();
    char get_character();

private:
    int _number;
    char _character;
};

#endif
