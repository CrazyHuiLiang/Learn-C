#include <stdio.h>

/* 将指针 t 指向的字符串复制到指针 s 指向的位置； 使用指针方式实现的版本2 */
void strcpy3(char *s, char *t) {
	while((*s++ = *t++) != '\0'){}
}

/* 将指针 t 指向的字符串复制到指针 s 指向的位置； 使用指针方式实现的版本3 */
void strcpy4(char *s, char *t) {
	while(*s++ = *t++){}
}

int main(int argc, char **argv) {
	char arg[100];

	strcpy3(arg, *(argv +0));
	printf("arg = %s\n", arg);

	strcpy4(arg, *(argv +1));
	printf("arg = %s\n", arg);
	return 0;
}

