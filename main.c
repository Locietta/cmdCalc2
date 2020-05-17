#include "color.h"
#include "calcio.h"
#include "calc.h"
#include "error.h"
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
        ERROR_INFO err;
        if (*expr && (err = Calc(expr, &result)).error == NOT_ERROR) {
            colorPrintf(PINK, "result: ");
            colorPrintf(LIGHTCYAN, "%g\n", result);
        } else {
            ErrReport(err, expr);
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