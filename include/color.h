/**
 * @file color.h
 * @author Locietta 
 * @brief 提供简单的命令行彩色输出
 * 
 * (defined COLOR_H) 
 * This header provides a simple package 
 * of SetConsoleTextAttribute() in the windows.h
 * 
 * @version 0.3
 * @date 2020-05-09 (first version on 2019.12.20)
 * 
 */

#ifndef COLOR_H
#define COLOR_H
#include <stdio.h>
#include <windows.h>

// /**
//  * @defgroup color_defines 各种颜色的标识
//  * @brief 各种表示不同颜色的常量
//  * @{
//  */
#define DEFAULT LIGHTGRAY ///< windows console use LIGHTGREY as its default color

/**
 * @brief Type: TCOLOR 颜色标识符
 * 提供各种颜色的标识符
 */
typedef enum { BLACK,
               BLUE,
               GREEN,
               CYAN,
               RED,
               PURPLE,
               BROWN,
               LIGHTGRAY, ///< 命令行的默认颜色
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
 * 
 * 切换默认字体前景色至你指定的颜色
 * 是windows.h中那个长长的函数的宏函数简单包装
 * 
 * @par 示例代码:
 * @code
 *      setColor(RED);
 * @endcode
 */
#define setColor(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color)

/**
 * @brief colorPrintf 彩色printf输出
 * 
 * 这个函数以指定的颜色按printf的方式输出格式化字符串
 * 不会改变当前的默认字体颜色
 * 
 * @param[in] color 输出字体颜色
 * @param[in] _Format 格式化字符串
 * @param[in] ... 格式化字符串相应的参数
 * @return 与标准printf相同的返回值
 * 
 * @par 示例代码:
 * @code 
 *      colorPrintf(RED, "Try my magical colorPrintf() %d\n", 233);
 * @endcode
 */
int __CRTDECL colorPrintf(TCOLOR color, const char *const _Format, ...);

#endif // (!defined COLOR_H)