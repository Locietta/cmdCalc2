#include "color.h"
#include "calcio.h"
#include "calc.h"
#include <windows.h>
#include <stdio.h>

void titleLog(void);

int main(void) {
    char expr[100];
    double result = 0;
    setColor(WHITE);
    titleLog();
    colorPrintf(PURPLE, "Input > ");
    while (Expr_gets(expr, 100)) {
        if (*expr && !Calc(expr, &result)) {
            colorPrintf(PINK, "result: ");
            colorPrintf(LIGHTCYAN, "%g\n", result);
        }
        colorPrintf(PURPLE, "Input > ");
    }
    colorPrintf(YELLOW, "See you ~");
    Sleep(1000); // wait for a second ( 
    return 0;
}

void titleLog(void) {
    printf("This is a ");
    colorPrintf(BLUE, "command line calculator");
    printf(".\nJust type expresions freely, and we'll calculate it.\nAnd... if you wanna a ");
    colorPrintf(YELLOW, "quit, ");
    printf("type in ");
    colorPrintf(LIGHTRED, "^z ");
    printf("(");
    colorPrintf(LIGHTRED, "ctrl ");colorPrintf(YELLOW, "+ ");colorPrintf(LIGHTRED, "z");
    printf(") and the program would be ended.\n");
}