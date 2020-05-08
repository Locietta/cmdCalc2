#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node { // Node of circular linked list
    List prev, next;
    void *data;
} Node;

/* Private Functions Prototypes */

#define freeNode(node)    \
    do {                  \
        free(node->data); \
        free(node);       \
    } while (0)

/* Public Functions Prototypes */

