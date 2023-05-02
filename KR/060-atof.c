#include <stdio.h>
#include <ctype.h>


/* atof函数：把字符串s转换为响应的双精度浮点数 */
double atof(char s[]) {
	double val, power;
	int i, sign;
	// 跳过空白符
	for (i = 0; isspace(s[i]); i++) {
	}
	// 判断是否为负数
	sign = (s[i] == '-') ? -1: 1;
	// 如果首位是符号位，将下标后移一位
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.') {
		i++;
	}
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign * val / power;
}


int main(int argc, char *argv[]) {
	char *s = "12345.678";
	printf("result = %.8g", atof(s));
	return 0;
}
	