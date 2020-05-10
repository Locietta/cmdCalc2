/**
 * File: calc.h
 * -------------------------------------
 * author: @Locietta finished on 2020.5.10
 * (defined CALC_H)
 * This header defines several functions needed for calculation
 */

#ifndef CALC_H
#define CALC_H

#include "stack.h"
#include "queue.h"
#include <ctype.h>

/**
 * Data Structure -- opNode
 * Usage: queue exprQueue = newQueue(opNode);
 * -------------------------------------------
 * store operators and oprands(numbers)
 * opNode::type indicate the type it store (operator or oprand)
 */

typedef struct opNode {
    int type;  // 0: op, 1: num
    union { // C11 std
        char op[4];
        double num;
    };
} opNode;

int Calc(char *expr, double *result);


#endif // (!defined CALC_H)