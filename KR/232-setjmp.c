#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf env;

int main(int argc, char **argv) {
    if (setjmp(env) == 0) { // 直接调用 setjmp 时，转移到这里
        printf("if\n");
        longjmp(env, 2);
    } else { // 调用 longjmp 时，转移到这里
        printf("else\n");
    }

    /*
        注意事项：
        
        longjmp 恢复栈指针时，可能会造成栈不匹配问题。如果你在函数 A 中调用 setjmp，然后函数 A 返回了，之后在函数 B 中调用 longjmp，此时栈的状态与 setjmp 时保存的状态不一致，可能会引发未定义行为。因此，使用 setjmp 和 longjmp 时，必须确保它们操作的栈帧还有效。

        性能影响：由于 setjmp 和 longjmp 涉及寄存器和栈的保存与恢复，它们相对来说性能并不是特别高效。因此，不适合频繁使用。

        资源清理问题：由于 longjmp 会直接跳过函数的返回过程，因此可能会跳过一些需要手动清理的资源（例如打开的文件、动态分配的内存等）。在 C++ 中，如果 longjmp 跨越了包含局部对象的作用域，这些局部对象的析构函数将不会被调用，这会引发资源泄露。因此，setjmp 和 longjmp 需要谨慎使用。
    */
    system("pause");
    return 0;
}
