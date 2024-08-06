#include <sys/times.h>
#include <time.h>
#include <stdio.h>


// 打印执行耗时
clock_t console_time_reset();   // 标记开始计时的时间点
clock_t console_time();         // 打印从 console_time_reset/

/*
    打印当前程序运行消耗的时钟滴答数
*/
clock_t print_my_process_time();
