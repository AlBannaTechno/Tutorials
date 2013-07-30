#include <stdio.h>
#include <ctype.h>
#include <string.h>

void print_letters(char arg[], int arglen)
{
    int i = 0;

    for (i = 0; i < arglen; ++i) {
        if (isalpha(arg[i]) || isblank(arg[i])) {
            printf("'%c' == %d ", arg[i], arg[i]);
        }
    }

    printf("\n");
}

void print_arguments(int argc, char *argv[])
{
    int i = 0;

    for (i = 0; i < argc; ++i) {
        print_letters(argv[i], strlen(argv[i]));
    }
}

int main(int argc, char *argv[])
{
    print_arguments(argc, argv);
    return 0;
}
