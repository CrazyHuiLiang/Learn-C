#include <stdio.h>
/* binsearch函数：在v[0]<=v[1]<=v[2]<=...<=v[n-1]中查找x  */
int binsearch(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid -1;
    else if (x > v[mid])
      low = mid + 1;
    else /* 找到了匹配的值 */
      return mid;
  }
  return -1; /*没有匹配的值*/
}

int main(){

  int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = 10;
  int x = 5;

  int locate = binsearch(x, v, n);
	printf("locate = %d \n\n", locate);
	return 0;
}
