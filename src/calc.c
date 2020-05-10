#include "calc.h"
#include "stack.h"
#include "queue.h"
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
    union {   // C11 std
        char op[4];
        double num;
    };
} opNode;

/* Private Function Prototypes */

int op_prior(const char *op);

int op_argnum(const char *op);

queue exprAnalyser(const char *expr);

/* Function implementations */

/* Public functions */

int Calc(char *expr, double *result) {
    // TODO
    return 0;
}

/* Private Functions */

int op_prior(const char *op) {
    switch (strlen(op)) {
    case 1:
        switch (*op) {
        case '^':
            return 4;
        case '*': case '/': case '%':
			return 3;
		case '+': case '-': 
			return 2;
		case '=': 
			return 1;
		default :		
			return 0;
        }
    default: // functions have the highest prior
        return INT_MAX;
    }
}

queue exprAnalyser(const char *expr) {
}