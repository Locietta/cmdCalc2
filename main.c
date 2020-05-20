/**
 * @mainpage Project 1 -- 中缀计算器
 * 由王灵鑫、程国斐、赵萌三人小组完成
 * @section 特性
 * -# 彩色的交互界面
 * -# 支持小数运算
 * -# 函数名称不区分大小写
 * -# 空格和[Tab]会被忽略
 * -# 详细的错误提示
 * @section 算法
 * -# 基于调度场算法将中缀表达式转为后缀表达式
 * @section 数据结构
 * -# 抽象堆栈和抽象队列
 * @section 分工
 * -# 王灵鑫/Locietta @par 架构、调度场算法、彩色输出、(其它各种实现...)、注释和文档、code review & modify & merge
 * -# 程国斐 @par 表达式分析(从中缀表达式字符串变为中缀表达式队列)、测试
 * -# 赵萌   @par 括号匹配、错误报告设计、测试
 */

/**
 * @file main.c
 * @author 王灵鑫/Locietta 程国斐 赵萌 (https://github.com/Locietta/C_Class_Project1/tree/doxygenDoc)
 * @brief Project 1 -- 中缀计算器
 * @version 0.1
 * @date 2020-05-20
 * 
 * 
 */

#include "color.h"
#include "calcio.h"
#include "calc.h"
#include "error.h"
#include <windows.h>
#include <stdio.h>

/**
 * @brief 打印一个标题
 * 
 */
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
            colorPrintf(GREEN, "result: ");
            colorPrintf(LIGHTCYAN, "%g\n", result);
        } else if (*expr) {
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
    colorPrintf(LIGHTRED, "ctrl ");
    colorPrintf(YELLOW, "+ ");
    colorPrintf(LIGHTRED, "z");
    printf(") and the program would be ended.\n");
}