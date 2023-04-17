/*
	函数itoa：将数字n转换为字符串并保存到s中

	修改itoa函数，使的该函数可以接收三个参数，其中，第3个参数为最小字段宽度。为了保证转换后所得的结果至少具有第三个指定的最小宽度，
	在必要时应在所得结果的左边填充一定的空格
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

// 将数字n转换为字符串并保存到s中
void itoa(int n, char s[], int min_width) {
	int i, sign;
	sign = n; // 记录符号
	i = 0;
	do {
		int bit = ABS(n%10);
		char c = bit + '0'; // 取下一个数字;
		s[i++] = c;
	} while ((n/=10) != 0);  // 删除该数字

	if (sign < 0) {
		s[i++] = '-';
	}
	while (i<min_width) {
		s[i++] = ' ';
	}
	s[i] = '\0';
	reverse(s);
}


int main(int argc, char *argv[]) {
	int n = INT_MIN;
	char s[100] = {};
	int min_width = 20;
	itoa(n, s, min_width);
	printf("n=%d, min_width=%d, result=%s", n, min_width, s);
	return 0;
}
