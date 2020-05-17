/**
 * File: calc.c
 * -------------------------------------
 * author: @Locietta finished on 2020.5.17
 * This source file implements the header error.h
 */

#include "error.h"
#include "color.h"

/* Private Function Prototypes */

void ErrReport_unmatchedBrac(void);

void ErrReport_invalidNumber(void);

void ErrReport_unknownFuncName(void);

void ErrReport_unknownOperator(void);

void ErrReport_wrongSpliterPos(void);

void ErrReport_wrongOprandNum(void);

void ErrReport_divideByZero(void);

void ErrReport_nonIntegerMod(void);

/* Function Implementations */

/* Public Function */

void ErrReport(ERROR_FLAG error, char *expr) {
    if (error == NOT_ERROR) {
        return;
    }
    colorPrintf(RED, "error: ");
    printf("Can't calculate illegal expression ");
    colorPrintf(YELLOW, expr);
    putchar('\n');
    switch (error) {
    case ERROR_UNMATCHED_BRAC: ErrReport_unmatchedBrac(); break;
    case ERROR_INVALID_NUMBER: ErrReport_invalidNumber(); break;
    case ERROR_UNKNOWN_FUNC_NAME: ErrReport_unknownFuncName(); break;
    case ERROR_UNKNOWN_OP: ErrReport_unknownOperator(); break;
    case ERROR_WRONG_POSITION_ARGUMENT_SPLITER: ErrReport_wrongSpliterPos(); break;
    case ERROR_WRONG_OPRAND_NUMBER: ErrReport_wrongOprandNum(); break;
    case ERROR_DIVIDE_ZERO: ErrReport_divideByZero(); break;
    case ERROR_MOD_NONINTERGER: ErrReport_nonIntegerMod(); break;
    }
    puts("     ? Try again with a proper expression!");
}

/* Private Function */

void ErrReport_unmatchedBrac(void) {
    printf("     ? ");
    colorPrintf(CYAN, "unmatched brackets");
    printf(" in the expression...");
}

void ErrReport_invalidNumber(void) {
    printf("     ? ");
    colorPrintf(CYAN, "invalid number");
    printf(" in the expression...");
}

void ErrReport_unknownFuncName(void) {
    printf("     ? ");
    colorPrintf(CYAN, "invalid number");
    printf(" in the expression...");
}

