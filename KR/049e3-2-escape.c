#include <stdio.h>
/*escape：将字符串t复制到字符串s中，并在复制过程中将换行符、制表符等不可见字符分别转换为\n \t等相应的可见的转义字符序列*/
void escape(char s[], char t[]) {

}
int main(){

  char t[10];
  int i =0;
  char c;
  scanf("%s", t);

  while ((c=t[i++]) != EOF)
	  printf("%c \n\n", c);

  return 0;
}
