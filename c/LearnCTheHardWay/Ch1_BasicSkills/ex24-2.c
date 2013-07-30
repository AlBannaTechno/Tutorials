#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dbg.h"

#define MAX_DATA 100


typedef enum EyeColour {
    BLUE_EYES, GREEN_EYES, BROWN_EYES, BLACK_EYES, OTHER_EYES
} EyeColour;

const char *EYE_COLOUR_NAMES[] = {
    "Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
    int age;
    char first_name[MAX_DATA];
    char last_name[MAX_DATA];
    EyeColour eyes;
    float income;
} Person;

int main(int argc, char *argv[])
{
    Person you = {.age = 0, .eyes = OTHER_EYES, .income = 0};
    int i = 0;
    char *in = NULL;
    char buffer[MAX_DATA];

    printf("What's your first name? ");
    in = fgets(buffer, MAX_DATA-1, stdin);
    strncpy(you.first_name, strtok(buffer, " \n"), MAX_DATA);
    check(in != NULL, "Failed to read first name.");

    printf("What's your last name? ");
    in = fgets(buffer, MAX_DATA-1, stdin);
    strncpy(you.last_name, strtok(buffer, " \n"), MAX_DATA);
    check(in != NULL, "Failed to read last name.");

    printf("How old are you? ");
    in = fgets(buffer, MAX_DATA-1, stdin);
    check(in != NULL, "Failed to read age.");
    you.age = atoi(strtok(buffer, " \n"));

    printf("What colour are your eyes?\n");
    for (i = 0; i <= OTHER_EYES; ++i) {
        printf("%d) %s\n", i+1, EYE_COLOUR_NAMES[i]);
    }
    printf("> ");
    in = fgets(buffer, MAX_DATA-1, stdin);
    check(in != NULL, "Failed to read eye colour.");
    you.eyes = atoi(strtok(buffer, " \n")) - 1;
    check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Do it right, that's not an option.");

    printf("How much do you make an hour? ");
    in = fgets(buffer, MAX_DATA-1, stdin);
    check(in != NULL, "Failed to read income.");
    you.income = atof(strtok(buffer, " \0"));
    check(you.income > 0, "Enter a floating point number above 0.");

    printf("---- RESULTS ----\n");
    printf("First Name: %s\n", you.first_name);
    printf("Last Name: %s\n", you.last_name);
    printf("Age: %d\n", you.age);
    printf("Eyes: %s\n", EYE_COLOUR_NAMES[you.eyes]);
    printf("Income: %f\n", you.income);

    return 0;

error:
    return 1;
}
