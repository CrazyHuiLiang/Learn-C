#include <stdio.h>

/* shellsort函数： 按递增顺序对v[0]...v[n-1]进行排序 */
void shellsort(int v[], int n) {
  int gap, i, j, temp;

  for (gap = n/2; gap > 0; gap /=2) { // 控制两个比较元素之间的距离
    for (i = gap; i< n; i++) {        // 用于元素间移动位置，从第一个gap作为下标的位置，向后遍历至数组结尾
      for (j=i-gap; j>=0; j-=gap) {   // 依次向前比较各对相距gap个位置的元素
        if (v[j]>v[j+gap]) {          // 逆序则交换
          temp = v[j];
          v[j] = v[j+gap];
          v[j+gap] = temp;
        }
      }
    }
  }
}

int main(){
  
  int v[] = {1, 3, 9, 2, 11, 18, 19, 5};
  int n = 8;
  shellsort(v, n);
  for (int i=0; i< n; i++)
	  printf("%d, ", v[i]);
	return 0;
}
