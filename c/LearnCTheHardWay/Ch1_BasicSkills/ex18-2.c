#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

void die(const char *message)
{
    if (errno) {
        perror(message);
    }
    else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

int *insertion_sort(int *numbers, int count)
{
    int i = 0;
    int j = 0;
    int cur_value = 0;
    for (i = 0; i < count; ++i) {
        cur_value = numbers[i];
        j = i;
        while (j > 0 && numbers[j-1] > cur_value) {
            numbers[j] = numbers[j-1];
            --j;
        }
        numbers[j] = cur_value;
    }

    return numbers;
}

int main(int argc, char *argv[])
{
    if (argc < 2) die("USAGE: ex18-2 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if (!numbers) die("Memory error");

    for (i = 0; i < count; ++i) {
        numbers[i] = atoi(inputs[i]);
    }

    printf("\nUnsorted numbers: ");
    for (i = 0; i < count; ++i) {
        printf("%d, ", numbers[i]);
    }

    numbers = insertion_sort(numbers, count);
    printf("\nSorted numbers: ");
    for (i = 0; i < count; ++i) {
        printf("%d, ", numbers[i]);
    }

    free(numbers);

    return 0;
}
