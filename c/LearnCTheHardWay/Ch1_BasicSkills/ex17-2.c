#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_SIZE 10

struct Stack {
    int cur_size;
    int data[MAX_SIZE];
};

void die(const char *message, struct Stack *stk);

struct Stack* Stack_create()
{
    struct Stack *stk = malloc(sizeof(struct Stack));
    if (!stk) die("Failed to create stack.", stk);

    stk->cur_size = 0;
    int i = 0;
    for (i = 0; i < MAX_SIZE; ++i) {
        stk->data[i] = -1;
    }

    return stk;
}

void Stack_delete(struct Stack *stk)
{
    if (stk) {
        free(stk);
    }
}

int Stack_push(struct Stack *stk, int value)
{
    if (stk->cur_size != MAX_SIZE) {
        stk->data[stk->cur_size] = value;
        stk->cur_size++;
        return 1;
    }
    else {
        return 0;
    }
}

int Stack_pull(struct Stack *stk)
{
    if (stk->cur_size != 0) {
        int value = stk->data[stk->cur_size-1];
        stk->data[stk->cur_size-1] = -1;
        stk->cur_size--;
        return value;
    }
    else {
        return 0;
    }
}

int main(int argc, char *argv[])
{
    struct Stack *stk = Stack_create();

    int i = 0;
    int value = 0;
    for (i = 0; i < MAX_SIZE; ++i) {
        printf("stack %d: %d\n", i, stk->data[i]);
    }
    printf("Stack size: %d\n", stk->cur_size);

    for (i = 0; i < 20; ++i) {
        if (Stack_push(stk, i+5)) {
            printf("Successfully added %d to stack.\n", i+5);
        }
        else {
            printf("Error: Stack overflow\n");
            break;
        }
    }

    printf("Stack size: %d\n", stk->cur_size);
    if (Stack_push(stk, 250)) {
        printf("Well, this shouldn't have happened, guess it broke when pushing.\n");
    }
    else {
        printf("Yay! Pushing didn't work!\n");
    }

    for (i = 0; i < 20; ++i) {
        value = Stack_pull(stk);
        if (value) {
            printf("Successfully removed %d from stack.\n", value);
        }
        else {
            printf("Error: stack underflow\n");
            break;
        }
    }

    printf("Stack size: %d\n", stk->cur_size);
    value = Stack_pull(stk);
    if (value) {
        printf("Well, this shouldn't have happened, guess it broke when pulling.\n");
    }
    else {
        printf("Yay! Pulling didn't work!\n");
    }

    Stack_delete(stk);
    return 0;
}

void die(const char *message, struct Stack *stk)
{
    if (errno) {
        perror(message);
    }
    else {
        printf("ERROR: %s\n", message);
    }

    Stack_delete(stk);

    exit(1);
}
