#include <stdio.h>

/* charToInt 函数：将字符串s转换为相应的整型数  */
int charToInt(char s[]) {
  int i,n;
  n = 0;
  for(i=0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10*n + (s[i] - '0');
  return n;
}


int main(){

  char c[]= "1234567";
  int i = charToInt(c);
  
	printf("%d \n", i);
	return 0;
}
