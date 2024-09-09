/*
    头文件 <string.h> 中定义了两组字符串函数
    第一组函数的名字以 str 开头
    第二组函数的名字以 mem 开头
    除函数 memmove 外，其他函数都没有定义重叠对象间的复制行为
    比较函数将把参数作为 unsigned char 类型的数组来看待

    https://cplusplus.com/reference/cstring/
*/
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
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

    /*
        int strcmp(cs, ct)
        比较字符串 cs 和 ct；
            当 cs < ct 时，返回一个负数（-1）
            当 cs == ct 时，返回 0
            当 cs > ct 时，返回一个正数（1）
    */
    printf("strcmp: %d\n", strcmp("abcd", "bcd"));  // -1
    printf("strcmp: %d\n", strcmp("abcd", "abcd")); // 0
    printf("strcmp: %d\n", strcmp("bcd", "abcd"));  // 1

    /*
        int strncmp(cs, ct, n)
        比较字符串 cs 和 ct 的前 n 个字符；
            当 cs < ct 时，返回一个负数（-1）
            当 cs == ct 时，返回 0
            当 cs > ct 时，返回一个正数（1）
    */
    printf("strncmp: %d\n", strncmp("abcd", "acd", 1));  // 0
    printf("strncmp: %d\n", strncmp("abcd", "abcd", 1)); // 0
    printf("strncmp: %d\n", strncmp("bcd", "bbcd", 1));  // 0

    /*
        char *strchr(const char *cs, int c)
        返回指定字符 c 在字符串 cs 中第一次出现的位置的指针；如果 cs 中不包含 c，则函数返回 NULL
     */
    printf("strchr: %s\n", strchr("abcd", 'c'));         // cd
    printf("strchr: %d\n", strchr("abcd", 'c') == NULL); // 0
    printf("strchr: %s\n", strchr("abcd", 'e'));         // (null)
    printf("strchr: %d\n", strchr("abcd", 'e') == NULL); // 1

    /*
        char *strrchr(const char *cs, int c)
        返回指定字符 c 在字符串 cs 中最后一次出现的位置的指针；如果 cs 中不包含 c，则函数返回 NULL
     */
    printf("strrchr: %s\n", strrchr("abcd", 'c'));         // cd
    printf("strrchr: %d\n", strrchr("abcd", 'c') == NULL); // 0
    printf("strrchr: %s\n", strrchr("abcd", 'e'));         // (null)
    printf("strrchr: %d\n", strrchr("abcd", 'e') == NULL); // 1

    /*
        size_t strspn(cs, ct)
        返回字符串 cs 中包含 ct 中的字符的前缀的长度
    */
    printf("strspn: %zu\n", strspn("abcdefg", "abcd")); // 4

    /*
        size_t strcspn(cs, ct)
        返回字符串 cs 中不包含 ct 中的字符的前缀的长度
    */
    printf("strcspn: %zu\n", strcspn("abcdefg", "bcd")); // 1
    printf("strcspn: %zu\n", strcspn("abcdefg", "cd"));  // 2
    printf("strcspn: %zu\n", strcspn("abcdefg", "def")); // 3

    /*
        char *strpbrk(cs, ct)
        返回一个指针，它指向字符串 ct 中任意字符第一次出现在字符串 cs 中的位置
        如果 cs 中没有与 ct 相同的字符，则返回 NULL
    */
    char str[] = "This is a sample string";
    char key[] = "aeiou";
    char *pch;
    printf("Vowels in '%s': ", str);
    pch = strpbrk(str, key);
    while (pch != NULL)
    {
        printf("%c ", *pch); // 出现过的元音字母有 i i a a e i
        pch = strpbrk(pch + 1, key);
    }
    printf("\n");

    return 0;
}
