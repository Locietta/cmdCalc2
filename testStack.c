#include "stack.h"
#include <stdio.h>

int main(void) {
    stack mystack = newStack(int);
    int input = 0, out = 0;
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &input);
        mystack.push(&mystack, &input);
    }
    while (mystack.size - 1) {
        mystack.pop(&mystack, &out);
        printf("%d ", out);
    }
    putchar('\n');
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &input);
        mystack.push(&mystack, &input);
    }
    printf("%d\n", *(int *)mystack.top(&mystack));
    while (mystack.size) {
        mystack.pop(&mystack, &out);
        printf("%d ", out);
    }
    mystack.clear(&mystack);
    return 0;
}