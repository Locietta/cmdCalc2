#include <stdio.h>
#include "stack.h"
#include "calcio.h"
#include "color.h"

static int bracketMatched(const char *expr) {
    stack brac_stack = newStack(char);
    const char *str = expr;
    char buf;
    while (*str != '\0') {
        switch (*str) {
        case '{':
        case '[':
        case '(': brac_stack.push(&brac_stack, str); break;
        case '}':
        case ']':
            if (brac_stack.pop(&brac_stack, &buf) == POP_IN_EMPTY_STACK || buf + 2 != *str) {
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
        ++str;
    }
    if (brac_stack.empty(&brac_stack)) {
        brac_stack.destory(&brac_stack);
        return 1;
    } else {
        brac_stack.destory(&brac_stack);
        return 0;
    }
}

int main(void) {
    char str[100];
    while (Expr_gets(str, 100)) {
        if (bracketMatched(str)) {
            colorPrintf(GREEN, "yes!\n");
        } else {
            colorPrintf(RED, "no...\n");
        }
    }
    return 0;
}