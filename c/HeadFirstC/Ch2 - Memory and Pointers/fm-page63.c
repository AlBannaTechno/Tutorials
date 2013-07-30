#include <stdio.h>

int main()
{
    int doses[] = {1, 3, 2, 1000};
    // just 4 different ways of outputting the value at the given array index
    printf("Issue dose %i - %i - %i - %i", doses[3], *(doses+3), *(3+doses), 3[doses]);

    return 0;
}
