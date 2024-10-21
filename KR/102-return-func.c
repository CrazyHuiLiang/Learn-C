/*
    非书中案例
    将函数指针作为返回值
*/
#include <stdio.h>

/* typedef 声明按照普通的声明方式将一个类型指派给其声明符中的每个名字 */
typedef void (*func_ptr_t)();

void func1() {
    printf("this is func1\n");
}

func_ptr_t func_gen() {
    return func1;
}


int main(int argc, char **argv) {
    func_ptr_t f = func_gen();
    f();
    return 0;
}

