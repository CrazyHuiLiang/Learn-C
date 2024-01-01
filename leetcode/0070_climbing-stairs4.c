// 70 爬楼梯 https://leetcode.cn/problems/climbing-stairs/
#include <stdio.h>
#include <stdlib.h>

/*
	解法3，使用递推
	算法复杂度 O(n)
	使用三个 int 值存储运算过程中的值
*/
int climbStairs(int n) {
	if (n < 3) {
		return n;
	}
	register int n1 = 1;
	register int n2 = 2;
	register int n2_buff;
	for (int i=2; i<n; i++) {
		n2_buff = n2;
		n2 = n1 + n2;
		n1 = n2_buff;
	}
	return n2;
}

int main(int argc, char *argv[]) {
	printf("%d\n", climbStairs(45));
	return 0;
}
