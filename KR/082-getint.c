#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/*
	getint函数：将输入中的下一个整型数赋值给*pn
*/
int getint(int *pn) {
	int c, sign;
	while (isspace(c = getch())) {
	}
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); // 输入不是一个数字
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
	}
	for (*pn = 0;isdigit(c);c = getch()) {
		*pn = 10 * *pn + (c - '0');
	}
	*pn *= sign;
	if (c != EOF) {
		ungetch(c);
	}
	return c;
}

int main(int argc, char *argv[]) {
	int SIZE = 100;
	int n, array[SIZE];
	for(n = 0; n< SIZE && getint(&array[n]) != EOF; n++) {
		
	}
}

