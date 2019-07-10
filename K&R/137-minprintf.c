//
// Created by Crazyhuiliang on 2019-03-28.
//

#include <stdio.h>
#include <stdarg.h>

// minprintf函数: 带有可变参数表的简化的printf函数
void minprintf(char *fmt, ...);

int main(int argc, char *argv[]) {
    minprintf("I am is minprintf test: %d, %f, %s", 100, 15.18, "end.");
    return 0;
}

void minprintf(char *fmt, ...) {
    va_list ap; // 依次指向每个无名参数
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++) {
                    putchar(*sval);
                }
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); // 结束时的清理工作
}