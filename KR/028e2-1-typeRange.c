/**
 * 编写一个程序分别确定 signed 和 unsigned 限定的 char、short、int、long类型变量的取值范围。
 * 方法1：打印标准头文件中相应值
 * 方法2：直接计算两种方式的实现
*/
#include <stdio.h>
#include <limits.h>

int main () {
  // 方法1
  printf("CHAR_BIT = %d\n", CHAR_BIT);
  printf("CHAR_MIN = %d\n", CHAR_MIN);
  printf("CHAR_MAX = %d\n", CHAR_MAX);
  printf("UCHAR_MAX = %u\n", UCHAR_MAX);
  printf("\n");
  
  printf("SHRT_MIN = %d\n", SHRT_MIN);
  printf("SHRT_MAX = %d\n", SHRT_MAX);
  printf("USHRT_MAX = %u\n", USHRT_MAX);
  printf("\n");

  printf("INT_MIN = %d\n", INT_MIN);
  printf("INT_MAX = %d\n", INT_MAX);
  printf("UINT_MAX = %u\n", UINT_MAX);
  printf("\n");
  
  printf("LONG_BIT = %d\n", LONG_BIT);
  printf("LONG_MIN = %ld\n", LONG_MIN);
  printf("LONG_MAX = %ld\n", LONG_MAX);
  printf("ULONG_MAX = %lu\n", ULONG_MAX);
  printf("\n");

  // 方法2： 以short为例
  unsigned short ushrt_max = 0;
  ushrt_max = ~ushrt_max;
  short shrt_max = ushrt_max >> 1;
  short shrt_min = ushrt_max ^ shrt_max;
  printf("shrt_min = %hd\n", shrt_min);
  printf("shrt_max = %hd\n", shrt_max);
  printf("ushrt_max = %u  \n", ushrt_max);
  printf("\n");

return 0;
  // 方法2: 以int为例
  // 以累计的方法是一个笨方法，一直将int值加到溢出，其位模式就是int_min, 将其值减去1得到的就是int_max
  int int_min = 0;
  int int_max = 0;
  unsigned int uint_max = 0;
  
  for (;int_max>=0; int_max++) {
  }
  int_min = int_max;
  int_max--;
  uint_max = (unsigned int)int_min + (unsigned int)int_max;
  
  printf("INT_MIN = %d\n", int_min);
  printf("INT_MAX = %d\n", int_max);
  printf("UINT_MAX = %u\n", uint_max);
  printf("\n");
  
  
  return 0;
}
