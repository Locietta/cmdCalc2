/**
 * file color.h
 * @author Locietta 
 * @brief 提供简单的命令行彩色输出
 * 
 * (defined COLOR_H) 
 * This header provides a simple package 
 * of SetConsoleTextAttribute() in the windows.h
 * 
 * @version 0.3
 * @date 2020-05-20 (first version on 2019.12.20)
 * 
 */

#ifndef COLOR_H
#define COLOR_H
#include <stdio.h>
#include <windows.h>

/**
 * @defgroup color_defines 各种颜色的标识
 * @brief 各种表示不同颜色的常量
 * 
 */
#define DEFAULT LIGHTGRAY ///< windows console use LIGHTGREY as its default color

/**
 * @brief Type: TCOLOR 颜色标识符
 * provides identifiers for font color
 */
typedef enum { BLACK,
               BLUE,
               GREEN,
               CYAN,
               RED,
               PURPLE,
               BROWN,
               LIGHTGRAY, ///< console default color
               DRAKGREY,
               LIGHTBLUE,
               LIGHTGREEN,
               LIGHTCYAN,
               LIGHTRED,
               PINK,
               YELLOW,
               WHITE } TCOLOR;

/**
 * @brief macro: setColor 切换默认字体颜色
 * switch the default font foreground color to whatever you want.
 * A simple macro as a substitution for the long function name.
 * @par example:
 * @code
 *      setColor(RED);
 * @endcode
 */
#define setColor(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color)

/**
 * @brief colorPrintf 彩色printf输出
 * 
 * This function prints format string in given color
 * it won't change the font color you currently use
 * 
 * @param[in] color 输出字体颜色
 * @param[in] _Format 格式化字符串
 * @param[in] ... 格式化字符串相应的参数
 * @return 与标准printf相同的返回值
 * 
 * @par example:
 * @code 
 *      colorPrintf(RED, "Try my magical colorPrintf() %d\n", 233);
 * @endcode
 */
int __CRTDECL colorPrintf(TCOLOR color, const char *const _Format, ...);

#endif // (!defined COLOR_H)