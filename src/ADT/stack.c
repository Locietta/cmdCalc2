#include "stack.h"
#include <stdlib.h>
typedef struct Node { // Node of circular linked list
    List prev, next;
    void *data;
} Node;

/* Public functions prototypes */

static int stackTop(stack *this);
static void stackPop(stack *this, void *target);
static void stackPush(stack *this, void *data);

static void stackDestory(stack *this);

/* Function implementations */

/* Public functions */

void stackInit(stack *this) {
    this->head = (List) calloc(1, sizeof(Node));

    this->top = stackTop;
}