#include <stdio.h>

/* 交换两个数的值 */
void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
int main(){

  int x = 5;
  int y = 1;
  swap(&x, &y);
	printf("%d,%d", x, y);
	return 0;
}
