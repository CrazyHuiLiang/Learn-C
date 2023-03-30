/*
	函数itoa：将数字n转换为字符串并保存到s中
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
void itoa(int n, char s[]) {
	int i, sign;
	
	/* 原题错误实现
	if ((sign = n) < 0) { // 记录符号
		n = -n; 			// 使n成为正数
	}
	i = 0;
	do {
		s[i++] = n%10 + '0'; // 取下一个数字
	} while ((n/=10) > 0);  // 删除该数字
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
	*/
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
	s[i] = '\0';
	reverse(s);
}


int main(int argc, char *argv[]) {
	// TIP: 使用s[]声明的字符数组，其内容是可以修改的；使用 *s 声明的字符串是常量，其内容不可修改
	char s[100] = {};
	itoa(INT_MIN, s);
	printf("%s", s);
	return 0;
}