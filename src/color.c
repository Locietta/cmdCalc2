/**
 * @file color.c
 * @author Locietta
 * @brief color.h 的实现,自定义了一个printf函数
 * @version 0.1
 * @date 2020.5.9 
 * 
 * 
 */

#include "color.h"
#include <stdarg.h>
#include <stdio.h>
#include <windows.h>

int __CRTDECL colorPrintf(TCOLOR color, _Printf_format_string_ const char *const _Format, ...) {
    CONSOLE_SCREEN_BUFFER_INFO bInfo;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hOut, &bInfo);
    int curColor = bInfo.wAttributes & 0xf; // get current color
    // CloseHandle(hOut);

    int result;
    va_list args;
    setColor(color);
    va_start(args, _Format);
    result = vprintf(_Format, args);
    va_end(args);
    setColor(curColor);
    return result;
}