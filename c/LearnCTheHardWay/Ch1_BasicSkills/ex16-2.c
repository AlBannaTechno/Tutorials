#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    int height;
    int weight;
} Person;

void Person_print(Person who)
{
    printf("Name: %s\n", who.name);
    printf("\tAge: %d\n", who.age);
    printf("\tHeight: %d\n", who.height);
    printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[])
{
    Person nick = {"Nick", 24, 63, 300};
    Person_print(nick);

    nick.age += 20;
    nick.height -= 2;
    nick.weight -= 100;
    Person_print(nick);

    return 0;
}
