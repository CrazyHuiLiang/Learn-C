#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline2(char s[], int lim) {
	int c, i;
	i = 0;
	while (--lim>0 && (c=getchar()) != EOF && c!='\n')
		s[i++] = c;
	if (c=='\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}


/*
 *	打印与第一个参数指定的模式匹配的行
 *	程序可以带两个可选的参数，可选参数应该允许任意次序出现
 *	-x 打印除匹配模式之外的所有行
 *	-n 每个打印的文本行前面加上相应的行号
 * */
int main(int argc, char **argv) {
	char line[MAXLINE];
	int found = 0;
	if (argc != 2) {
		printf("Usage: find pattern\n");
	} else {
		while (getline2(line, MAXLINE) > 0) {
			if (strstr(line, argv[1]) != NULL) {
				printf("%s", line);
				found++;
			}
		}
	}
	return found;
}

