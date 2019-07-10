#include <stdio.h>

/* 16进制字符串转化为数字,字符串可选前缀0x 或 0X，允许包含数字0～9、a～f、A～F */
int htoi(char s[]){
  char c;
  int number=0;

  for(int i=0; ( c = s[i] ) != '\0'; i++) {
    if ((i==0 && c == '0') || (i==1 && (c=='x'|| c=='X')) )
      continue;
    if (c>='0' && c<='9')
      number = number * 16 + (c-'0');
    else if (c>='a' && c<='f')
      number = number * 16 + (c-'a'+10);
    else if (c>='A' && c<='F')
      number = number * 16 + (c-'A'+10);
  }
  return number;
}

int main(){

  char c[] = "0X123b";
  int number = htoi(c);

	printf("%d \n", number);
	printf("ox%x \n", number);
	return 0;
}
