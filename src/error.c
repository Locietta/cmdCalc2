/**
 * File: calc.c
 * -------------------------------------
 * author: @Locietta finished on 2020.5.17
 * This source file implements the header error.h
 */

#include "error.h"
#include "color.h"

/* Private Function Prototypes */

static void ErrReport_unmatchedBrac(void);

static void ErrReport_invalidNumber(char *number);

static void ErrReport_unknownFuncName(char *funcName);

static void ErrReport_unknownOperator(char op);

static void ErrReport_wrongSpliterPos(void);

static void ErrReport_wrongOprandNum(void);

static void ErrReport_divideByZero(void);

static void ErrReport_nonIntegerMod(void);

/* Function Implementations */

/* Public Function */

void ErrReport(ERROR_INFO err, char *expr) {
    if (err.error == NOT_ERROR) {
        return;
    }
    colorPrintf(RED, "error: ");
    printf("Can't calculate illegal expression ");
    colorPrintf(YELLOW, "\"%s\"", expr);
    printf("\n");
    switch (err.error) {
    case NOT_ERROR: break;
    case ERROR_UNMATCHED_BRAC: ErrReport_unmatchedBrac(); break;
    case ERROR_INVALID_NUMBER: ErrReport_invalidNumber(err.number); break;
    case ERROR_UNKNOWN_FUNC_NAME: ErrReport_unknownFuncName(err.funcName); break;
    case ERROR_UNKNOWN_OP: ErrReport_unknownOperator(err.op); break;
    case ERROR_WRONG_POSITION_ARGUMENT_SPLITER: ErrReport_wrongSpliterPos(); break;
    case ERROR_WRONG_OPRAND_NUMBER: ErrReport_wrongOprandNum(); break;
    case ERROR_DIVIDE_ZERO: ErrReport_divideByZero(); break;
    case ERROR_MOD_NONINTERGER: ErrReport_nonIntegerMod(); break;
    }
    puts("     ? Try again with a proper expression!");
}

/* Private Function */

static void ErrReport_unmatchedBrac(void) {
    printf("     ? ");
    colorPrintf(RED, "unmatched brackets");
    printf(" in the expression...\n");
}

static void ErrReport_invalidNumber(char *number) {
    printf("     ? ");
    colorPrintf(RED, "invalid number ");
    colorPrintf(YELLOW, number);
    putchar('\n');
}

static void ErrReport_unknownFuncName(char *funcName) {
    printf("     ? ");
    colorPrintf(RED, "unknown function name ");
    colorPrintf(YELLOW, funcName);
    putchar('\n');
}

static void ErrReport_unknownOperator(char op) {
    printf("     ? ");
    colorPrintf(RED, "unknown function name ");
    colorPrintf(YELLOW, "%c", op);
    putchar('\n');
}

static void ErrReport_wrongSpliterPos(void) {
    printf("     ? ");
    colorPrintf(RED, "wrong position");
    printf(" for the function argument spliter");
    colorPrintf(YELLOW, " ,\n");
}

static void ErrReport_wrongOprandNum(void) {
    printf("     ? ");
    colorPrintf(RED, "oprand number unmatched");
    printf(" in the expression...\n");
}

static void ErrReport_divideByZero(void) {
    printf("     ? ");
    colorPrintf(RED, "0 as a divisor");
    printf(" in the expression...\n");
}

static void ErrReport_nonIntegerMod(void) {
    printf("     ? try to do ");
    colorPrintf(RED, "modular");
    printf(" calculation between ");
    colorPrintf(RED, "non-integers");
}