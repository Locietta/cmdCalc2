#include "queue.h"
#include <stdio.h>

int main(void) {
    queue myqueue = newQueue(double);
    double input = 0, out = 0;
    printf("Push 5> ");
    for (int i = 0; i < 5; ++i) {
        scanf("%lf", &input);
        myqueue.push(&myqueue, &input);
    }
    printf("Pop 4> ");
    while (myqueue.size - 1) {
        myqueue.pop(&myqueue, &out);
        printf("%g ", out);
    }
    putchar('\n');
    printf("Push 3> ");
    for (int i = 0; i < 3; ++i) {
        scanf("%lf", &input);
        myqueue.push(&myqueue, &input);
    }
    printf("Front> ");
    printf("%g\n", *(double *) myqueue.front(&myqueue));
    printf("Back> ");
    printf("%g\n", *(double *) myqueue.back(&myqueue));
    myqueue.clear(&myqueue);
    if (myqueue.empty(&myqueue)) {
        puts("Now the stack is empty");
    }
    printf("Push 3> ");
    for (int i = 0; i < 3; ++i) {
        scanf("%lf", &input);
        myqueue.push(&myqueue, &input);
    }
    printf("Front> ");
    printf("%g\n", *(double *) myqueue.front(&myqueue));
    printf("Back> ");
    printf("%g\n", *(double *) myqueue.back(&myqueue));
    printf("Pop 3> ");
    while (myqueue.size) {
        myqueue.pop(&myqueue, &out);
        printf("%g ", out);
    }
    myqueue.destory(&myqueue);
    return 0;
}