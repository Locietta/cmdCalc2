/**
 * File: error.c
 * -------------------------------------
 * author: @Locietta finished on 2020.5.17
 * This source file implements the header error.h
 */

#include "./include/error.h"
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

static void ErrReport_nonPostiveLog(void);

/* Function Implementations */

/* Public Function */

void ErrReport(ERROR_INFO err, char *expr) {
    if (err.error == NOT_ERROR) {
        return;
    }
    colorPrintf(RED, "error : ");
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
    case ERROR_NEGATIVE_IN_LOG: ErrReport_nonPostiveLog(); break;
    }
    puts("      ? Try again with a proper expression!");
}

/* Private Function */

static void ErrReport_unmatchedBrac(void) {
    printf("      ? ");
    colorPrintf(CYAN, "unmatched brackets");
    printf(" in the expression...\n");
}

static void ErrReport_invalidNumber(char *number) {
    printf("      ? ");
    colorPrintf(CYAN, "invalid number ");
    colorPrintf(YELLOW, "%s", number);
    putchar('\n');
    free(number);
}

static void ErrReport_unknownFuncName(char *funcName) {
    printf("      ? ");
    colorPrintf(CYAN, "unknown function name ");
    colorPrintf(YELLOW, funcName);
    putchar('\n');
    free(funcName);
}

static void ErrReport_unknownOperator(char op) {
    printf("      ? ");
    colorPrintf(CYAN, "unknown operator ");
    colorPrintf(YELLOW, "%c", op);
    putchar('\n');
}

static void ErrReport_wrongSpliterPos(void) {
    printf("      ? ");
    colorPrintf(CYAN, "wrong position");
    printf(" for the function argument spliter");
    colorPrintf(YELLOW, " ,\n");
}

static void ErrReport_wrongOprandNum(void) {
    printf("      ? ");
    colorPrintf(CYAN, "oprand number unmatched");
    printf(" in the expression...\n");
}

static void ErrReport_divideByZero(void) {
    printf("      ? ");
    colorPrintf(CYAN, "0 as a divisor");
    printf(" in the expression...\n");
}

static void ErrReport_nonIntegerMod(void) {
    printf("      ? try to do ");
    colorPrintf(CYAN, "modular");
    printf(" calculation between ");
    colorPrintf(CYAN, "non-integers\n");
}

static void ErrReport_nonPostiveLog(void) {
    printf("      ? passing ");
    colorPrintf(CYAN, "negative");
    printf(" number to ");
    colorPrintf(CYAN, "ln");
    printf(" function\n");
}