/*
    可变参数表 <stdarg.h>
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void fun1(int count, ...) {
    va_list ap;
    va_start(ap, count);
    int sum = 0;
    for (int i=1; i<=count; i++) {
        int param = va_arg(ap, int);
        sum += param;
        if (i < count) {
            printf("%d+", param);
        } else {
            printf("%d=", param);
        }
    }
    printf("%d\n", sum);
    va_end(ap);
}

int main(int argc, char **argv) {
    fun1(1, 1);
    fun1(2, 1, 2);
    fun1(3, 1, 2, 3);
    fun1(4, 1, 2, 3, 4);

    system("pause");
    return 0;
}
