/*
快速排序
*/
#include <stdio.h>

void qsort(int v[], int left, int right);

int main(int argc, char *argv[]) {
	int n = 10;
	int v[] = {1, 3, 6, 4, 5, 2, 7, 8, 9, 0};
	qsort(v, 0, n-1);
	for (int i=0; i<n; i++) {
		printf("%d ", v[i]);
	}
}

void print_int_array(int v[], int n, char *space) {
	printf("%s", space);
	for (int i=0; i<n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

/*
对于一个给定的数组，从中选择一个元素，以该元素为界将其余元素划分为两个子集，
一个子集中的所有元素都小于该元素，另一个子集中的所有元素都大与或等于该元素。
对这样两个子集递归执行这一过程，当某个子集中的元素数小于2时，这个子集就不需
要再次排序，终止递归。
*/
void qsort(int v[], int left, int right) {
	int i, last;
	void swap(int v[], int i, int j);

	printf("\nleft=%d, right=%d\n", left, right);
	print_int_array(v, 10, "sort ");
	
	if (left >= right) {
		return;
	}
	swap(v, left, (left + right)/2); /* 将划分子集的元素 */
	print_int_array(v, 10, "swap ");

	last = left;					/* 移动到v[0] */
	for (i = left+1; i<=right; i++) {/* 划分子集 */
		if (v[i] < v[left]) {
			swap(v, ++last, i);
		}
		print_int_array(v, 10, "     ");
	}
	swap(v, left, last);			/* 恢复划分子集的元素 */
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap函数：交换 v[i] 与 v[j] 的值 */
void swap(int v[], int i, int j) {
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
