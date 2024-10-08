#include <stdio.h>

/* 根据 s 按照字典顺序小于、等于或大于 t 的结果分别返回负整数、0 或正整数 */
int strcmp1(char *s, char *t) {
	int i;
	for (i=0; s[i]==t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}

/* 根据 s 按照字典顺序小于、等于或大于 t 的结果分别返回负整数、0 或正整数，使用指针实现 */
int strcmp2(char *s, char *t) {
	for (; *s==*t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

int main(int argc, char **argv) {
	printf("s1 cmp s2 = %d\n", strcmp1("hello", "hellp"));
	printf("s1 cmp s2 = %d\n", strcmp1("hello", "hello"));
	printf("s1 cmp s2 = %d\n", strcmp1("hello", "hella"));
	printf("s1 cmp s2 = %d\n", strcmp2("hello", "hellp"));
	printf("s1 cmp s2 = %d\n", strcmp2("hello", "hello"));
	printf("s1 cmp s2 = %d\n", strcmp2("hello", "hella"));
	return 0;
}

