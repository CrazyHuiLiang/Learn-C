#include <stdio.h>

/* strlen函数： 返回字符串s的长度  */
int strlen1(char s[]) {
  int n;
  for (n=0; *s != '\0'; s++)
    n++;
  return n;
}

int main(){
  char a[] = "hello";
  char *p = a;
  p++;

	printf("%d", strlen1(p));
	return 0;
}
