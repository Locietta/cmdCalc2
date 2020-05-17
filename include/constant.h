/**
 * File: constant.h
 * -------------------------------------
 * author: @Locietta finished on 2020.5.17
 * (defined CONSTANT_H)
 * This header defines some constant 
 * to identify length limits
 */

// 本来不会有这玩意的，但是不提取出来的话calc.h和error.h就会循环包含(当场暴毙)

#ifndef CONSTANT_H
#define CONSTANT_H

/**
 * Constants -- MAX_FUNC_NAME
 * -------------------------------------------
 * defines the maximum length of the function name 
 */

#define MAX_FUNC_NAME 7

/**
 * Constants -- MAX_NUMBER
 * -------------------------------------------
 * defines the maximum length of a number 
 */

#define MAX_NUMBER 50



#endif // (!defined CONSTANT_H)