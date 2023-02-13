#include <stdio.h>
/*escape：将字符串t复制到字符串s中，并在复制过程中将换行符、制表符等不可见字符分别转换为\n \t等相应的可见的转义字符序列*/
void escape(char s[], char t[]) {
  int i = 0;
  int j = 0;
  do {
    switch (t[i]) {
    case '\n':
      s[j++] = '\\';
      s[j++] = 'n';
      break;
    
    case '\t':
      s[j++] = '\\';
      s[j++] = 't';
      break;
    
    default:
      s[j++] = t[i];
      break;
    }
  } while (t[i++] != '\0');
}

// 与escape功能相反
void rev_escape(char s[], char t[]) {
  int i = 0;
  int j = 0;
  while (t[i] != '\0') {
    if (t[i] != '\\') {
      s[j++] = t[i++];
      continue;
    }
    switch (t[i+1]) {
      case 'n':
        s[j++] = '\n';
        i+=2;
        break;
      
      case 't':
        s[j++] = '\t';
        i+=2;
        break;
      
      default:
        s[j++] = t[i++];
        break;
    }
  }
}


int main(){
  char t[] = "abcd\n\t1234";
  char s[100];
  escape(s, t);
  printf("%s\n", s);
  rev_escape(s, s);
  printf("%s\n", s);
  return 0;
}
