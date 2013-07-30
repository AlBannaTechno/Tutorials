#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    // go through each string in argv. Why am I skipping argv[0]? It containts the program name duh
    for(i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings
    char *states[] = {"California", "Oregon", "Washington", NULL};
    int num_states = 4;

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    argv[1] = states[1];
    states[1] = argv[0];
    printf("state %s, arg %s\n", states[1], argv[1]);

    return 0;
}
