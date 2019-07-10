#include <stdio.h>

/* lower函数：把字符c转换为小写形式；只对ASCII字符集有效 */
int lower(int c) {
  if (c >= 'A' && c <='Z')
    return c + 'a' - 'A';
  else
    return c;
}

int main(){

  char c;
  while ((c=getchar()) != EOF)
	  printf("%c \n", lower(c));
	return 0;
}
