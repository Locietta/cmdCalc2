#include "stack.h"
#include <stdlib.h>
#include <string.h>

typedef struct Node { // Node of circular linked list
    List prev, next;
    void *data;
} Node;

/* Private Functions Prototypes */

stack stackInit(size_t size);

#define freeNode(node)    \
    do {                  \
        free(node->data); \
        free(node);       \
    } while (0)

/* Public Functions Prototypes */

static const void *stackTop(stack *this);
static void stackPop(stack *this, void *target);
static void stackPush(stack *this, void *data);

static void stackDestory(stack *this);

/* Function implementations */

/* Public functions */

stack stackInit(size_t size) {
    stack newstack;
    newstack.head = (List) calloc(1, sizeof(Node));
    newstack.elemSize = size;
    newstack.head->data = malloc(newstack.elemSize);

    if (newstack.head) {
        newstack.head->prev = newstack.head;
        newstack.head->next = newstack.head;
    } else {
        puts("Stack initalization falied");
        return;
    }

    newstack.size = 0;
    newstack.top = stackTop;
    newstack.pop = stackPop;
    newstack.push = stackPush;
    newstack.destroy = stackDestory;

    return newstack;
}

static const void *stackTop(stack *this) {
    return this->head->prev->data;
}

static void stackPop(stack *this, void *target) {
    if (target) { // target != NULL
        memmove(target, this->head->prev->data, this->elemSize);
    }

    if (this->size > 1) {
        List temp = this->head->prev;
        this->head->prev = this->head->prev->prev;
        this->head->prev->next = this->head;
        freeNode(temp);
    }
    --this->size;
}
static void stackPush(stack *this, void *data) {
    if (this->size) {
        List newNode = (List) calloc(1, sizeof(Node));
        newNode->data = malloc(this->elemSize);
        memmove(newNode->data, data, this->elemSize);

        newNode->next = this->head;
        newNode->prev = this->head->prev;
        newNode->prev->next = newNode;
        newNode->next->prev = newNode;
    } else { // empty stack
        memmove(this->head->data, data, this->elemSize);
    }
    ++this->size;
}

static void stackDestory(stack *this) {
    while (this->head->prev != this->head) {
        List temp = this->head->prev;
        this->head->prev = this->head->prev->prev;
        this->head->prev->next = this->head;
        freeNode(temp);
    }
    freeNode(this->head);
}