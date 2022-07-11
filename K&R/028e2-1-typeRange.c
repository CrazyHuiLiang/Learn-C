#include <stdio.h>

int main () {
  int i = 1e2;
  float f = 1e-2;

  printf("%d\n", i);
  printf("%f\n",f);
  printf("%d", '\00f');
  // 不会做。。
  return 0;
}
