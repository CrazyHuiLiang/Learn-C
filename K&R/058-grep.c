#include <stdio.h>
#define MAXLINE 1000 /*最大输入行长度*/
int getLine(char line[], int max);
int strIndex(char source[], char searchFor[]);

char pattern[] = "ould"; /*待查找的模式*/

/* 找出所有与模式匹配的行 */
int main(){
  
  char line[MAXLINE];
  int found = 0;

  while (getLine(line, MAXLINE) >0)
    if (strIndex(line, pattern) >=0) {
	    printf("%s", line);
      found++;
    }
  printf("end %d", found);
	return found;
}


/* getLine函数： 将行保存到s中，并返回该行的长度 */
int getLine(char s[], int lim) {
  int c, i;
  i = 0;
  while (--lim >0 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\n';
  return i;
}

/* strIndex 函数： 返回t在s中的位置，若未找到则返回-1 */
int strIndex(char s[], char t[]) {
  int i, j, k;
  for (i=0; s[i] != '\n'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++);
    if (k>0 && t[k]=='\0')
      return i;
  }
  return -1;
}



