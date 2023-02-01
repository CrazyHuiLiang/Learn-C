/* 每行一个单词的形式打印其输出 */
#include <stdio.h>

int main() {
	int c;
	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\t') {
			printf("\n");
		} else {
			putchar(c);
		}
	}
	return 0;
}
