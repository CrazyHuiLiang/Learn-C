// 70 爬楼梯 https://leetcode.cn/problems/climbing-stairs/
#include <stdio.h>
#include <stdlib.h>

/*
	解法1，使用递归；减而治之
	算法复杂度 O(2^n)
	优点：代码简单
	缺点：递归过程有大量重复计算，效率随着计算规模的增大迅速下降，大于100的数计算时长超长或无法求解
*/
int climbStairs(int n) {
	if (n < 3) {
		return n;
	}
	return climbStairs(n -1) + climbStairs(n - 2);
}

int main(int argc, char *argv[]) {
	printf("%d\n", climbStairs(100));
	return 0;
}
