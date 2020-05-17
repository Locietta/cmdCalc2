/**
 * File: error.h
 * -------------------------------------
 * author: @赵萌
 * modified by @Locietta on 2020.5.10
 * (defined ERROR_H)
 * This header defines several functions examine the error
 * in expression ready to calculate
 */

#ifndef ERROR_H
#define ERROR_H
#include "color.h"
#include "queue.h"
#include "stack.h"
#include "calc.h"
#include <stdio.h>

/**
 * enumerate type -- ERROR_FLAG
 * -------------------------------------------
 * identifier for error-reporting
 */

typedef enum ERROR_FLAG {
    NOT_ERROR,
    ERROR_UNMATCHED_BRAC,
    ERROR_INVALID_NUMBER,
    ERROR_UNKNOWN_FUNC_NAME,
    ERROR_UNKNOWN_OP,
    ERROR_WRONG_POSITION_ARGUMENT_SPLITER,
    ERROR_WRONG_OPRAND_NUMBER,
    ERROR_DIVIDE_ZERO,
    ERROR_MOD_NONINTERGER
} ERROR_FLAG;

/**
 * union -- ERROR_INFO
 * -------------------------------------------
 * provide all the information needed for error-reporting
 */

typedef struct ERROR_INFO {
    ERROR_FLAG error;
    union {
        char funcName[MAX_FUNC_NAME + 1];
    };
} ERROR_INFO;

/**
 * Function: ErrReport
 * Usage: ErrReport(ERROR_INVALID_NUMBER, expr);
 * ---------------------------
 * All-in-one error-report function
 * first argument allow the function identify the type of error
 * second argument tells the function the whole expression calculated
 */

void ErrReport(ERROR_INFO error, char *expr);

#endif // (!defined ERROR_H)