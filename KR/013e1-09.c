/*
	编写一个将输入复制到输出的程序，并将其中连续多个空格用一个空格代替
*/

#include <stdio.h>


int main(int argc, char *argv[]) {
	
	printf("please input something:\n");
	int c;
	int black = 0;
	while ((c = getchar()) != EOF) {
		// 记录遇到过空白符
		if (c == ' ' || c == '\t') {
			black = 1;
			continue;
		}
		// 在遇到非空白符时将之前记录的空白符打印为一个空格
		if (black) {
			putchar(' ');
		}
		black = 0;
		// 输出当前的字符
		putchar(c);
	}
	
	printf("done");
	return 0;
}