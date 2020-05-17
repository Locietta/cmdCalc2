/**
 * File: calc.h
 * -------------------------------------
 * author: @Locietta finished on 2020.5.10
 * (defined CALC_H)
 * This header defines several functions needed for calculation
 */

#ifndef CALC_H
#define CALC_H

/**
 * Constants -- MAX_FUNC_NAME
 * -------------------------------------------
 * defines the maximum function name length
 */

#define MAX_FUNC_NAME 7

/**
 * Function: Calc
 * Usage: Calc(expr, &result);
 * ---------------------------
 * This function calculate the expression given by 'expr'
 * its result will be put into the 'result'
 * If everything is OK, it shall return 0
 * Otherwise, it returns a non-zero value indicating errors
 */

int Calc(char *expr, double *result);


#endif // (!defined CALC_H)