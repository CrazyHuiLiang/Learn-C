/*
编写一个将输入复制到输出的程序，并将其中连续多个空格用一个空格代替
*/
#include <stdio.h>
#define NOBLANK 'a'

int main(int argc, char *argv[]) {
	int c, lastic;
	lastic = NOBLANK;
	while ((c = getchar()) != EOF) {
		// 当前字符不为空，或者上次记录的字符如果不为空
		if (c != ' ' || lastic != ' ') {
			putchar(c); // 打印字符
		}
		// 记录本次读取的字符
		lastic = c;
	}
}
