/*
编写一个统计空格、制表符与换行符个数的程序
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
	printf("please input something:\n");
	int sc, tc, nc, c;
	sc = tc = nc = 0;
	while ((c = getchar()) != EOF) {
		switch (c) {
			case ' ': sc++; break;
			case '\t': tc++; break;
			case '\n': nc++; break;
		}
	}
	printf("\nspace count: %d, \\t count: %d, \\n count: %d", sc, tc, nc);
	return 0;
}
