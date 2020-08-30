/* 2 在美国，通常是以英里每加仑来计算油耗，在欧洲则是以升每百公里来计算。下面是某程
 * 序的一部分，该程序让用户选择一个模式（公制的或美制的），然后收集数据来计算油耗。
 * //pe12-2b.c
 * // 与pe12-2a.c一起编译
 * #include <stdio.h>
 * #include "pe12-2a.h"
 * #int main(void)
 * {
 *     int mode;
 *     printf("Enter 0 for metric mode, 1 for US mode: ");
 *     scanf("%d", &mode);
 *     while(mode >= 0)
 *     {
 *         set_mode(mode);
 *         get_info();
 *         show_info();
 *         printf("Enter 0 for metric mode, 1 for US mode");
 *         printf(" (-1 to quit): ");
 *         scanf("%d", &mode);
 *     }
 *     printf("Done!\n");
 *     return 0;
 * }
 * 下面是一些输出示例：
 * Enter 0 for metric mode, 1 for US mode: 0
 * Enter distance traveled in kilometers: 600
 * Enter fuel consumed in liters: 78.8
 * Fuel consumption is 13.13 liters per 100 km.
 * Enter 0 for metric mode, 1 for US mode (-1 to quit): 1
 * Enter distance traveled in miles: 434
 * Enter fuel consumed in gallons: 12.7
 * Fuel consumption is 34.2 miles per gallon.
 * Enter 0 for metric mode, 1 for US mode (-1 to quit): 3
 * Invalid mode specified. Mode 1(US) used.
 * Enter distance traveled in miles: 388
 * Enter fuel consumed in gallons: 15.3
 * Fuel consumption is 25.4 miles per gallon.
 * Enter 0 for netric, 1 for US mode (-1 to quit): -1
 * Done.
 * 如果用户输入了不正确的模式，程序向用户给出提示消息并使用上一次输入的正确模式。
 * 请提pe12-2a.h头文件和pe12-2a.c源文件，源代码文件应定义3个具有文件作用域、内
 * 部链接的变量。一个表示模式，一个表示距离，一个表示消耗的燃料。get_info()函数
 * 根据用户输入的模式提示用户输入相关数据，并将其储存到文件作用域变量中。show_info()
 * 函数根据设置的模式计算并显示油耗。可以假设用户输入的都是数值数据。
 */

