/**
 * File: color.h
 * -------------------------------------
 * author: @Locietta finished on 2019.12.20 last modified on 2020.5.9
 * (defined COLOR_H)
 * This header provides a simple package 
 * of SetConsoleTextAttribute() in the windows.h 
 */

#ifndef COLOR_H
#define COLOR_H
#include <stdio.h>
#include <windows.h>

/**
 * Constants -- colors
 * ------------------------
 * different kinds of color
 * windows console use LIGHTGREY as its default color
 */

typedef enum { BLACK,
               BLUE,
               GREEN,
               CYAN,
               RED,
               PURPLE,
               BROWN,
               LIGHTGRAY, // console default color
               DRAKGREY,
               LIGHTBLUE,
               LIGHTGREEN,
               LIGHTCYAN,
               LIGHTRED,
               PINK,
               YELLOW,
               WHITE } TCOLOR;

/**
 * Macro: setColor
 * Usage: setColor(RED);
 * ---------------------------
 * set the default font color to what you want 
 */

#define setColor(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color)

/**
 * Function: colorPrintf
 * Usage: colorPrintf(RED, "Try my magical colorPrintf() %d\n", 233);
 * ---------------------------
 * This function prints format string in given color
 * it won't change the font color you currently use
 */

int __CRTDECL colorPrintf(TCOLOR color, const char *const _Format, ...);

#endif // (!defined COLOR_H)