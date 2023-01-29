#include <stdio.h>

// 计算字符串长度
int strlen(char s[]){
  int i=0;
  while (s[i] != '\0')
    ++i;
	return i;
}

int main() {
  char s[] = "123456";
  int len = strlen(s);
  printf("%i", len);
  return 0;
}
