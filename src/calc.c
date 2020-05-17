#include "calc.h"
#include "stack.h"
#include "queue.h"
#include "error.h"
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

/**
 * Constants -- MAX_FUNC_NAME
 * -------------------------------------------
 * defines the maximum function name length
 */

#define MAX_FUNC_NAME 7

/**
 * Constants -- TYPE_NUM TYPE_OP TYPE_FUNC
 * -------------------------------------------
 * identifier of opNode::type
 */

enum { TYPE_NUM, TYPE_OP, TYPE_FUNC, TYPE_IDENTIFIER };

/**
 * Constants -- LEFT RIGHT
 * -------------------------------------------
 * identifier for op_associate()
 */

enum { LEFT, RIGHT };

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
        char op[MAX_FUNC_NAME + 1];
        double num;
    };
} opNode;

/* Private Function Prototypes */

static int op_prior(const char *op);

static int op_argnum(const char *op);

static int op_associate(const char *op);

static int calcSingle(char *op, double num[], double *result);

static int exprAnalyzer(const char *expr, queue *infixRes);

static int convert2Postfix(queue infix, queue *postfixRes);

static int bracketMatched(const char *expr);

static const char *numberFetcher(const char *expr, double *result);

static const char *functionFetcher(const char *expr, char* funcName);

static int isFunction(char *name);

#define isOperator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '%' || c == '=' || c == '^')

#define isLeftBrac(c) (c == '(' || c == '{' || c == '[')

#define isRightBrac(c) (c == ')' || c == '}' || c == ']')

#define isNum(c) (isdigit(c) || c == '.')

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
        case '^': return 4;
        case '*':
        case '/':
        case '%': return 3;
        case '+':
        case '-': return 2;
        case '=': return 1;
        default: return 0;
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
        case '=': // here '=' means 'compare'
            return 2;
        default: return -1; // unknown operator
        }
        break;
    default:
        if (!strcmp(op, "sin")) {
            return 1;
        } else if (!strcmp(op, "cos")) {
            return 1;
        } else if (!strcmp(op, "ln")) {
            return 1;
        } else if (!strcmp(op, "exp")) {
            return 1;
        } else if (!strcmp(op, "pow")) {
            return 2;
        } else {
            return -2; // unknown function
        }
    }
}

static int op_associate(const char *op) {
    if (!strcmp(op, "^")) {
        return RIGHT;
    } else {
        return LEFT;
    }
}

static int calcSingle(char *op, double num[], double *result) {
    switch (strlen(op)) {
    case 1:
        switch (*op) {
        case '+': *result = num[0] + num[1]; break;
        case '-': *result = num[0] - num[1]; break;
        case '*': *result = num[0] * num[1]; break;
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
                // puts("% operation demands integers");
                return 2;
            }
            break;
        case '^': *result = pow(num[0], num[1]); break;
        case '=': *result = (num[0] == num[1]); break;
        }
        break;
    default:
        if (!strcmp(op, "sin")) {
            *result = sin(num[0]);
        } else if (!strcmp(op, "cos")) {
            *result = cos(num[0]);
        } else if (!strcmp(op, "ln")) {
            *result = log(num[0]);
        } else if (!strcmp(op, "exp")) {
            *result = exp(num[0]);
        } else if (!strcmp(op, "pow")) {
            *result = pow(num[0], num[1]);
        }
        break;
    }
    return 0;
}

static int exprAnalyzer(const char *expr, queue *infixRes) {

    if (!bracketMatched(expr)) {
        // puts("brackets unmatched");
        return 1;
    }

    // /* this if-block is not neccessary */
    // if (!isalnum(*expr) && !isLeftBrac(*expr) && *expr == '.') {
    //     // puts("not begin with number, function or parenthese");
    //     return 2;
    // }

    queue infix = newQueue(opNode);
    const char *start = expr;
    while (*expr) {
        if (isNum(*expr) || ((*expr == '-' || *expr == '+') && ((!isdigit(*(expr - 1)) && isNum(*(expr + 1))) || expr == start))) {
            opNode tempNode = {TYPE_NUM, .num = 0};
            if ((expr = numberFetcher(expr, &tempNode.num))) {
                infix.push(&infix, &tempNode);
            } else {
                // puts("invalid number");
                infix.destory(&infix);
                return 2;
            }
        } else if (isalpha(*expr)) {
            opNode tempNode = {TYPE_FUNC, .op = ""};
            if ((expr = functionFetcher(expr, (char *) &tempNode.op))) {
                infix.push(&infix, &tempNode);
            } else {
                // puts("unknown function name");
                infix.destory(&infix);
                return 3;
            }
        } else if (isOperator(*expr)) {
            opNode tempNode = {TYPE_OP, .op = ""};
            tempNode.op[0] = *(expr++);
            tempNode.op[1] = '\0';
            infix.push(&infix, &tempNode);
        } else if (*expr == ',' || isLeftBrac(*expr) || isRightBrac(*expr)) {
            opNode tempNode = {TYPE_IDENTIFIER, .op = ""};
            tempNode.op[0] = *(expr++);
            tempNode.op[1] = '\0';
            infix.push(&infix, &tempNode);
        } else {
            // puts("unknown operator");
            infix.destory(&infix);
            return 4;
        }
    }
    *infixRes = infix;
    return 0;
}

static const char *numberFetcher(const char *expr, double *result) {
    char buf[50], *numstr = buf;
    const char *start = expr;

    while (isdigit(*expr) || *expr == '.') {
        if (isdigit(*expr)) {
            *(numstr++) = *(expr++);
        } else if (expr != start) { // && *expr == '.'
            char *temp = numstr - 1, flag = 1;
            while (temp >= buf) {
                if (*(temp--) == '.') {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                *(numstr++) = *(expr++);
            } else {
                return NULL; // one number with two (or more) '.' e.g. 1.23.5
            }
        }
    }
    *numstr = '\0';
    sscanf(buf, "%lf", result);
    return expr;
}

static int isFunction(char *name) {
    return !(strcmp(name, "sin") && strcmp(name, "cos") && strcmp(name, "ln") && strcmp(name, "exp") && strcmp(name, "pow"));
}

static const char *functionFetcher(const char *expr, char* funcName) {
    char buf[MAX_FUNC_NAME + 1], *funcstr = buf;
    while (isalpha(*expr)) {
        *(funcstr++) = *(expr++);
    }
    *funcstr = '\0';
    if (isFunction(buf)) {
        strcpy(funcName, buf);
        return expr;
    } else {
        return NULL;
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

static int convert2Postfix(queue infix, queue *postfixRes) {
    queue postfix = newQueue(opNode);
    stack opstack = newStack(opNode);

    while (!infix.empty(&infix)) {
        opNode tempNode;
        infix.pop(&infix, &tempNode);

        if (tempNode.type == TYPE_NUM) {
            postfix.push(&postfix, &tempNode);
        } else if (tempNode.type == TYPE_FUNC) {
            opstack.push(&opstack, &tempNode);
        } else if (!strcmp(tempNode.op, ",")) {
            while (!opstack.empty(&opstack)) {
                opNode optemp;
                opstack.pop(&opstack, &optemp);
                if (isLeftBrac(optemp.op[0])) {
                    opstack.push(&opstack, &optemp);
                    break;
                } else {
                    postfix.push(&postfix, &optemp);
                }
            }
            if (opstack.empty(&opstack)) {
                // puts("wrong postion for function argument spliter ','");
                postfix.destory(&postfix); // caution leakage
                opstack.destory(&opstack);
                infix.destory(&infix);

                return 1;
            }
        } else if (tempNode.type == TYPE_OP) {
            while (!opstack.empty(&opstack)) {
                if ((op_prior(((opNode *) opstack.top(&opstack))->op) > op_prior(tempNode.op)) ||
                    (op_prior(((opNode *) opstack.top(&opstack))->op) == op_prior(tempNode.op) && op_associate(tempNode.op) == LEFT)) {

                    opNode optemp;
                    opstack.pop(&opstack, &optemp);
                    postfix.push(&postfix, &optemp);
                } else {
                    break;
                }
            }
            opstack.push(&opstack, &tempNode);
        } else if (isLeftBrac(tempNode.op[0])) {
            opstack.push(&opstack, &tempNode);
        } else if (isRightBrac(tempNode.op[0])) {
            while (!opstack.empty(&opstack) && !isLeftBrac(((opNode *) opstack.top(&opstack))->op[0])) {
                opNode optemp;
                opstack.pop(&opstack, &optemp);
                postfix.push(&postfix, &optemp);
            }
            opstack.pop(&opstack, NULL); // clean left bracket
        }
    }
}