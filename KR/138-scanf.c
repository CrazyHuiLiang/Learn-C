#include <stdio.h>


void sp1() {
    int day, year;
    char monthname[20];
    printf("please input 1:\n");
    // 从键盘中进行输入时，会使用空白符分割单词边界
    int n = scanf("%d%s%d", &day, monthname, &year);
    printf("count of inputs:%d\n", n);
    printf("%d/%s/%d\n", year, monthname, day);
}

void sp2() {
    int day, year;
    char monthname[20];
    printf("please input 2:\n");
    // %s如果不指定宽度，会把后面的所有输入都匹配上
    int n = scanf("%d-%4s-%d", &day, monthname, &year);
    printf("count of inputs:%d\n", n);
    printf("%d/%s/%d\n", day, monthname, year);
}

int main() {
    // sp1();
    sp2();
    return 0;
}
