#include "queue.h"
#include <stdio.h>

int main(void) {
    queue myqueue = newQueue(int);
    int input = 0, out = 0;
    printf("Push 5> ");
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &input);
        myqueue.push(&myqueue, &input);
    }
    printf("Pop 4> ");
    while (myqueue.size - 1) {
        myqueue.pop(&myqueue, &out);
        printf("%d ", out);
    }
    putchar('\n');
    printf("Push 3> ");
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &input);
        myqueue.push(&myqueue, &input);
    }
    printf("Front> ");
    printf("%d\n", *(int *) myqueue.front(&myqueue));
    printf("Back> ");
    printf("%d\n", *(int *) myqueue.back(&myqueue));
    myqueue.clear(&myqueue);
    if (myqueue.empty(&myqueue)) {
        puts("Now the stack is empty");
    }
    printf("Push 3> ");
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &input);
        myqueue.push(&myqueue, &input);
    }
    printf("Front> ");
    printf("%d\n", *(int *) myqueue.front(&myqueue));
    printf("Back> ");
    printf("%d\n", *(int *) myqueue.back(&myqueue));
    printf("Pop 3> ");
    while (myqueue.size) {
        myqueue.pop(&myqueue, &out);
        printf("%d ", out);
    }
    myqueue.destory(&myqueue);
    return 0;
}