/*
	函数itob(n, s, b)：将数字n转换为以b为底数的数，将结果字符串并保存到s中
*/
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define ABS(X) ((X) > 0 ? (X) : -(X))

// 倒置字符串s中各个字符的位置
void reverse(char s[]) {
	for (int i=0, j=strlen(s)-1; i<j; i++,j--) {
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

// 函数itob(n, s, b)：将数字n转换为以b为底数的数，将结果字符串并保存到s中
void itob(int n, char s[], int b) {
	int sign = n;
	int i = 0;
	while (n) {
		s[i++] = n%b + '0';
		n = n/b;
	}
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}


int main(int argc, char *argv[]) {
	int n = 100;
	char s[100] = {};
	char b = 16; // 底数
	itob(n, s, b);
	printf("n=%d, b=%d, result = %s", n, b, s);
	return 0;
}