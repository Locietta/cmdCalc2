/**
 * author: @Locietta
 * This header defines an abstract stack
 */

#ifndef STACK_H
#define STACK_H

typedef struct Node *List;

typedef struct stack_info stack;
struct stack_info { // container
    List head;      // data
    int size;        // the number of elements in the stack
    size_t elemSize;    // size of elements in the stack
    /* Public Function Prototypes */
    const void *(*top)(stack *this);
    void (*pop)(stack *this, void *target);
    void (*push)(stack *this, void *data);
    void (*destroy)(stack *this);
};

/* Construction Function */

/**
 * Function: newStack
 * Usage: mystack = newStack(double);
 * ---------------------------
 * This function initialize a stack with given type.
 */

#define newStack(type); stackInit(sizeof(type));

#endif // (!defined OPSTACK_H)