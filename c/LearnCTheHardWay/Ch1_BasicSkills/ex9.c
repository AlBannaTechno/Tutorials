#include <stdio.h>

int main(int argc, char *argv[])
{
    int numbers[4] = {0};
    int name[4] = {'a'};
    // this gives a memory error O_o shouldn't that be aaa\0?
    // char *name = "aaa";

    // first print them out raw
    printf("Numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
    printf("Name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]);
    printf("Name: %s\n", name);

    // setup the numbers
    numbers[1] = 1;
    numbers[2] = 2;
    numbers[3] = 3;
    numbers[4] = 4;

    // setup the name
    name[0] = 'Z';
    name[1] = 'e';
    name[2] = 'd';
    name[3] = '\0';

    // then print them out initialized
    printf("Numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
    printf("Name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]);
    printf("Name: %s\n", name);

    // another way to use name
    char *another = "Zed";

    printf("another: %s\n", another);

    printf("another each: %c %c %c %c\n", another[0], another[1], another[2], another[3]);

    return 0;
}
