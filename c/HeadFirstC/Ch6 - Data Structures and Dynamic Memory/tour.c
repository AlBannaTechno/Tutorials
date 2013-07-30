#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct island {
    const char *name;
    const char *opens;
    const char *closes;
    struct island *next;
} island;

island* create(char *name);
void display(island *start);
void release(island *start);


int main()
{
    // // create the islands
    // island amity = {"Amity", "09:00", "17:00", NULL};
    // island craggy = {"Craggy", "09:00", "17:00", NULL};
    // island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
    // island shutter = {"Shutter", "09:00", "17:00", NULL};

    // // link the islands together
    // amity.next = &craggy;
    // craggy.next = &isla_nublar;
    // isla_nublar.next = &shutter;

    // display(&amity);
    // printf("\n");

    // // add a new island to the route
    // island skull = {"Skull", "09:00", "17:00", NULL};
    // isla_nublar.next = &skull;
    // skull.next = &shutter;

    // display(&amity);

    island *start = NULL;
    island *i = NULL;
    island *next = NULL;
    char name[80];

    for (; fgets(name, 80, stdin) != NULL; i = next) {
        next = create(name);
        if (start == NULL)
            start = next;
        if (i != NULL)
            i->next = next;
    }

    display(start);
    release(start);

    return 0;
}

island* create(char *name)
{
    island *i = malloc(sizeof(island));
    i->name = strdup(name);
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

void display(island *start)
{
    island *i = start;

    for (; i != NULL; i = i->next)
        printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
}

void release(island *start)
{
    island *i = start;
    island *next = NULL;
    for (; i != NULL; i = next) {
        next = i->next;
        free(i->name);
        free(i);
    }
}
