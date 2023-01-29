/*
  编写一个将输入复制到输出的程序，并将其中的

  制表符替换为\t
  回退符替换为\b
  反斜杠替换为\\
*/

#include <stdio.h>

/*replace tabs and backspaces with visible characters*/
int main(){

  int c;
  while((c=getchar()) != EOF)
    if (c == '\t')
	    printf("\\t");
    else if (c == '\b')
      printf("\\b");
    else if (c == '\\')
      printf("\\\\");
    else
      putchar(c);
	return 0;
}
