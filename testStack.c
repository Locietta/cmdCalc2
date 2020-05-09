#include "stack.h"
#include <stdio.h>

int main(void) {
    stack mystack = newStack(int);
    int input = 0, out = 0;
    printf("Push 5> ");
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &input);
        mystack.push(&mystack, &input);
    }
    printf("Pop 4> ");
    while (mystack.size - 1) {
        mystack.pop(&mystack, &out);
        printf("%d ", out);
    }
    putchar('\n');
    printf("Push 3> ");
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &input);
        mystack.push(&mystack, &input);
    }
    printf("Top> ");
    printf("%d\n", *(int *) mystack.top(&mystack));
    mystack.clear(&mystack);
    if (mystack.empty(&mystack)) {
        puts("Now the stack is empty");
    }
    printf("Push 3> ");
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &input);
        mystack.push(&mystack, &input);
    }
    printf("Top> ");
    printf("%d\n", *(int *) mystack.top(&mystack));
    printf("Pop 3> ");
    while (mystack.size) {
        mystack.pop(&mystack, &out);
        printf("%d ", out);
    }
    return 0;
}