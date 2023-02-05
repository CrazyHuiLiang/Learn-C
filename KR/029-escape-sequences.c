#include <stdio.h>


int main() {
    printf("\a"); // 响铃符
    printf("\n- `\b` 回退符");
    printf("\n- `\f` 换页符");
    printf("\n- `\n` 换行符");
    printf("\n- `\r` 回车符");
    printf("\n- `\t` 横向制表符");
    printf("\n- `\v` 纵向制表符");
    printf("\n- `\"` 双引号");
    printf("\n- `\'` 单引号");
    printf("\n- `\\` 反斜杠本身");
    printf("\n- `\?` 问号");
    printf("\n- `\077` 三位八进制数");
    printf("\n- `\x88` 两位十六进制数");
    return 0;
}
