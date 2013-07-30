#include <stdio.h>

void first_method(int ages[], char *names[], int count)
{
    int i = 0;
    for (i = 0; i < count; ++i) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }
}

void second_method(int *cur_age, char **cur_name, int count)
{
    int i = 0;
    for (i = 0; i < count; ++i) {
        printf("%s is %d years old.\n", *(cur_name+i), *(cur_age+i));
    }
}

void third_method(int *cur_age, char **cur_name, int count)
{
    int i = 0;
    for (i = 0; i < count; ++i) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }
}

int main(int argc, char *argv[])
{
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {"Alan", "Frank", "Mary", "John", "Lisa"};
    int count = sizeof(ages) / sizeof(int);
    int *cur_age = ages;
    int **cur_name = names;

    first_method(ages, names, count);
    printf("---\n");
    second_method(cur_age, cur_name, count);
    printf("---\n");
    third_method(cur_age, cur_name, count);

    return 0;
}
