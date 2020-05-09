/**
 * author: @Locietta
 * This header defines an abstract stack
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#define NULL_QUEUE ((queue){NULL, 0, -1, NULL, NULL, NULL, NULL, NULL, NULL, NULL})

typedef struct Node *List;

typedef struct queue_info queue;
struct queue_info {  // container
    List head;       // data
    int size;        // the number of elements in the stack
    size_t elemSize; // size of elements in the stack

    /* Public Function Prototypes */

    int (*empty)(queue *this);

    const void *(*front)(queue *this);

    const void *(*back)(queue *this);

    int (*push)(queue *this, void *data);

    int (*pop)(queue *this, void *target);

    void (*clear)(queue *this);

    void (*destory)(queue *this);
};

/* Construction Function */

queue queueInit(size_t size);

#define newQueue(type) queueInit(sizeof(type))

#endif // (!defined Queue_H)