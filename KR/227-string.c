/*
    头文件 <string.h> 中定义了两组字符串函数
    第一组函数的名字以 str 开头
    第二组函数的名字以 mem 开头
    除函数 memmove 外，其他函数都没有定义重叠对象间的复制行为
    比较函数将把参数作为 unsigned char 类型的数组来看待
*/
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) {
    /*
        char *strcpy(s, ct)
        将字符串 ct（包括 '\0'）复制到字符串 s 中，并返回 s
        多次调用后，s为最后一次调用的 ct
    */
    char buff[100];
    strcpy(buff, "abcd");
    strcpy(buff, "efg");
    printf("%s\n", buff); // efg

    /*
        char *strncpy(s, ct, n)
        将字符串 ct 中最多 n 个字符复制到字符串 s 中，并返回 s（不会在 n 个字符后面添加 '\0'）
        如果 ct 中少于 n 个字符，则用 '\0' 填充
    */
    strncpy(buff, "abcd", 4);
    strncpy(buff, "efg", 1);
    printf("%s\n", buff); // ebcd
    strcpy(buff, "");

    /*
        char *strcat(s, ct)
        将字符串 ct 追加到 s 的尾步，并返回 s
    */
    strcat(buff, "abcd");
    strcat(buff, "efg");
    printf("%s\n", buff); // abcdefg
    strcpy(buff, "");

    /*
        char *strncat(s, ct, n)
        将字符串 ct 中最多 n 个字符追加到 s 的尾步，并以 '\0' 结束
        该函数返回 s
    */
    strncat(buff, "abcd", 2);
    strncat(buff, "efg", 2);
    printf("%s\n", buff); // abef
    strcpy(buff, "");



    return 0;
}
