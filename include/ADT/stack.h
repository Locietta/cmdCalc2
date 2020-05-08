/**
 * @Locietta
 * Abstract stack
 * 
 */

#ifndef STACK_H
#define STACK_H

typedef struct Node *List;

typedef struct stack_info stack;
struct stack_info { // container
    List head;      // data
    int len;        // the number of elements in the stack
    /* Public Function Prototypes */
    int (*top)(stack *this);
    void (*pop)(stack *this, void *target);
    void (*push)(stack *this, void *data);
    void (*destroy)(stack *this);
};

/* Construction Function Prototype */

void stackInit(stack *this);

#endif // (!defined OPSTACK_H)