// 70 爬楼梯 https://leetcode.cn/problems/climbing-stairs/
#include <stdio.h>
#include <stdlib.h>

/*
	解法3，使用递推
	算法复杂度 O(n)
	使用一个数组存储运算过程中产生的值
*/
int climbStairs(int n) {
	if (n < 3) {
		return n;
	}
	int *buff = malloc(n * sizeof(int));
	buff[0] = 1;
	buff[1] = 2;
	for (int i=2; i<n; i++) {
		buff[i] = buff[i-1] + buff[i-2];
	}
	int result = buff[n-1];
	free(buff);
	return result;
}

int main(int argc, char *argv[]) {
	printf("%d\n", climbStairs(45));
	return 0;
}
