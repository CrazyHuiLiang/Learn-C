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
#include <stdlib.h>

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

    /*
        char *strstr(cs, ct)
        返回一个指针，它指向字符串 ct 第一次出现在字符串 cs 中的位置
        如果 cs 中不包含字符串 ct，则返回 NULL
    */
    printf("strstr: %s\n", strstr("abcdabcd", "cd")); // cdabcd
    printf("strstr: %s\n", strstr("abcdabcd", "ef")); // (null)

    /*
        size_t strlen(cs)
        返回字符串 cs 的长度
    */
    printf("strlen: %d\n", strlen("123456789")); // 9

    /*
        char *strerror(n)
        返回一个指针，它指向与错误编号 n 对应的错误信息字符串（错误信息的具体内容与具体实现相关）
    */
    printf("strerror: 0 %s\n", strerror(0));
    printf("strerror: 1 %s\n", strerror(1));
    printf("strerror: 2 %s\n", strerror(2));
    printf("strerror: 3 %s\n", strerror(3));
    printf("strerror: 4 %s\n", strerror(4));
    printf("strerror: 5 %s\n", strerror(5));

    /*
        char *strtok(s, ct)
        在 s 中搜索由 ct 中的字符界定的记号
        进行一系列调用，可以把字符串 s 分成许多记号，这些记号以 ct 中的字符为分界符
            它搜索 s，找到不包含 ct 中字符的第一个记号，将记号的下一个字符替换为 '\0'，并返回记号的指针，随后，每次调用 strtok 函数时，均返回下一个不包含 ct 中字符的记号
            当 s 中没有这样的记号时，返回 NULL
            每次调用时字符串 ct 可以不同
    */
    char str2[] ="- This, a sample string.";
    char *pch2;
    printf ("Splitting string \"%s\" into tokens:\n",str);
    pch2 = strtok (str," ,.-");
    while (pch2 != NULL)
    {
        printf("%s\n",pch2);
        pch2 = strtok (NULL, " ,.-");
    }

    // 以 mem 开头的函数按照字节数组的方式操作对象，其主要目的是提供一个高效的函数接口（它可以操作任何数据类型，直接在内存中进行字节处理，不对字符串的 \0 进行判断，所以大多时候比 str 开头的函数性能更好）

    /*
        void *memcpy(s, ct, n)
        将字符串 ct 中的 n 个字符拷贝到 s 中，并返回 s
    */
    char memcpy_s[100];
    printf("memcpy: %s|'%d'\n", memcpy(memcpy_s, "abcdefg", 6), memcpy_s[6]);      // abcdef|'0'
    char *memcpy_r = memcpy(memcpy_s+2, memcpy_s, 4);
    // 如果源和目标内存区域重叠，memcpy 的行为是未定义的。这意味着它可能导致数据损坏或程序崩溃，因为 memcpy 可能在复制过程中覆盖源内存区域
    printf("memcpy_r: [%s] memcpy_s: [%s], memcpy_s %ld, memcpy_r: %ld\n", memcpy_r, memcpy_s, memcpy_s, memcpy_r); // memcpy_r: [abcd] memcpy_s: [ababcd], memcpy_s 6290768, memcpy_r: 6290770

    /*
        void *memmove(s, ct, n)
        与 memcpy 相似，不同的是，当对象重叠时，该函数仍能正确执行
    */
    char memmove_s[100] = "abcdef";
    char *memmove_r = memmove(memmove_s+2, memmove_s, 4);
    printf("memmove_s: %ld memcpy_s: [%s], memmove_r %ld, memcpy_r: [%s]\n", memcpy_s, memcpy_s, memcpy_r, memcpy_r); // memmove_s: 6290768 memcpy_s: [ababcd], memmove_r 6290770, memcpy_r: [abcd]

    /*
        int memcmp(cs, ct, n)
        将 cs 的前 n 个字符与 ct 进行比较，其返回值与 strcmp 的返回值相同
    */
    printf("memcmp: %d\n", memcmp("abcd", "abce", 3)); // 0
    printf("memcmp: %d\n", memcmp("abcd", "abce", 4)); // -1
    printf("memcmp: %d\n", memcmp("abcd", "abcb", 4)); // 1

    /*
        void *memchr(cs, c, n)
        返回一个指针，它指向 c 在 cs 中第一次出现的位置。如果在 cs 的前 n 个字符中找不到匹配，则返回 NULL
    */
    printf("memchr: %s\n", memchr("abcd", 'c', 4));         // cd
    printf("memchr: %d\n", memchr("abcd", 'c', 4) == NULL); // 0
    printf("memchr: %s\n", memchr("abcd", 'e', 4));         // (null)
    printf("memchr: %d\n", memchr("abcd", 'e', 4) == NULL); // 1

    /*
        void *memset(s, c, n)
        将 s 中的前 n 个字符替换为 c，并返回 s
    */
    char mem[10];
    mem[9] = '\0';
    printf("memset: %s, %d, %s\n", memset(mem, 'a', 9 /* 注意不能写10，最后一个字节留给字符串结束符 \0 */), strlen(mem), mem);
    printf("mem len: %u\n", strlen(mem));
    system("pause");
    return 0;
}
