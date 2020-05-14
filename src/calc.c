#include "calc.h"
#include "stack.h"
#include "queue.h"
#include "error.h"
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

/**
 * Data Structure -- opNode
 * Usage: queue exprQueue = newQueue(opNode);
 * -------------------------------------------
 * store operators and oprands(numbers)
 * opNode::type indicate the type it store (operator or oprand)
 */

typedef struct opNode {
    int type; // 0: op, 1: num
    union {   // C11 std: anoymous union
        char op[7];
        double num;
    };
} opNode;

/**
 * Constants -- TYPE_OP TYPE_NUM
 * -------------------------------------------
 * identifier of opNode::type
 */

enum { TYPE_OP,
       TYPE_NUM };

/* Private Function Prototypes */

static int op_prior(const char *op);

static int op_argnum(const char *op);

static int calcSingle(char *op, double num[], double *result);

static int exprAnalyser(const char *expr, queue *infixRes);

static int bracketMatched(const char *expr);

static char *numberFetcher();

/* Function implementations */

/* Public functions */

int Calc(char *expr, double *result) {
    // TODO
    return 0;
}

/* Private Functions */

static int op_prior(const char *op) {
    switch (strlen(op)) {
    case 1:
        switch (*op) {
        case '^':
            return 4;
        case '*':
        case '/':
        case '%':
            return 3;
        case '+':
        case '-':
            return 2;
        case '=':
            return 1;
        default:
            return 0;
        }
        break;
    default: // functions have the highest prior
        return INT_MAX;
    }
}

static int op_argnum(const char *op) {
    switch (strlen(op)) {
    case 1:
        switch (*op) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
        case '=': //here '=' means 'compare'
            return 2;
        default:
            return -1; // unknown operator
        }
        break;
    default:
        if (strcmp(op, "sin")) {
            return 1;
        } else if (strcmp(op, "cos")) {
            return 1;
        } else if (strcmp(op, "ln")) {
            return 1;
        } else if (strcmp(op, "exp")) {
            return 1;
        } else {
            return -2; // unknown function
        }
    }
}

static int calcSingle(char *op, double num[], double *result) {
    switch (strlen(op)) {
    case 1:
        switch (*op) {
        case '+':
            *result = num[0] + num[1];
            break;
        case '-':
            *result = num[0] - num[1];
            break;
        case '*':
            *result = num[0] * num[1];
            break;
        case '/':
            if (num[1]) {
                *result = num[0] / num[1];
            } else {
                // puts("0 can't be used as divide number")
                return 1;
            }

            break;
        case '%':
            if ((int) num[0] == num[0] && (int) num[1] == num[1]) {
                *result = (int) num[0] % (int) num[1];
            } else {
                //puts("% operation demands integers");
                return 2;
            }
            break;
        case '=':
            *result = (num[0] == num[1]);
        }
        break;
    default:
        if (strcmp(op, "sin")) {
            *result = sin(num[0]);
        } else if (strcmp(op, "cos")) {
            *result = cos(num[0]);
        } else if (strcmp(op, "ln")) {
            *result = log(num[0]);
        } else if (strcmp(op, "exp")) {
            *result = exp(num[0]);
        }
        break;
    }
    return 0;
}

static int exprAnalyser(const char *expr, queue *infixRes) {
    queue infix = newQueue(opNode);
    if (!bracketMatched(expr)) {
        // puts("brackets unmatched");
        return 1;
    }
    if (!isalnum(*expr) && *expr != '(') {
        //puts("not begin with number, function or parenthese");
        infix.destory(&infix);
        return 2;
    }
    
    while (*expr) {
        if (isdigit(*expr)) {
            const char *temp = expr;
            char buf[50]; 

        }
    }
}

static int bracketMatched(const char *expr) {
    stack brac_stack = newStack(char);
    char buf;
    while (*expr != '\0') {
        switch (*expr) {
        case '{':
        case '[':
        case '(': brac_stack.push(&brac_stack, expr); break;
        case '}':
        case ']':
            if (brac_stack.pop(&brac_stack, &buf) == POP_IN_EMPTY_STACK || buf + 2 != *expr) {
                brac_stack.destory(&brac_stack);
                return 0;
            }
            break;
        case ')':
            if (brac_stack.pop(&brac_stack, &buf) == POP_IN_EMPTY_STACK || buf != '(') {
                brac_stack.destory(&brac_stack);
                return 0;
            }
            break;
        }
        ++expr;
    }
    if (brac_stack.empty(&brac_stack)) {
        brac_stack.destory(&brac_stack);
        return 1;
    } else {
        brac_stack.destory(&brac_stack);
        return 0;
    }
}