#include <stdio.h>

/*统计输入字符数； 版本2*/
int main(){
   double nc;
   for(nc=0; getchar() != EOF; ++nc)
      ; // 单独的分号称为空语句
   printf("%.0f \n", nc);
}
