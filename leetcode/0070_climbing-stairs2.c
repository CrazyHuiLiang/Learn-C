// 70 爬楼梯 https://leetcode.cn/problems/climbing-stairs/
#include <stdio.h>
#include <stdlib.h>

/*
解法2，仍然使用递归，使用一个数组缓存计算过程中的值，规避重复计算
算法复杂度 O(n)
优点：代码简单，性能高
*/
int climbStairWithCache(int n, int *cache) {
	if (n < 3) {
		return n;
	}
	if (!cache[n]) {
		cache[n] = climbStairWithCache(n -1, cache) + climbStairWithCache(n - 2, cache);
	}
	return cache[n];
}
int climbStairs(int n) {
	int *buff = (void *)calloc(n, sizeof(int));
	return climbStairWithCache(n, buff);
}

int main(int argc, char *argv[]) {
	printf("%d\n", climbStairs(10));
	return 0;
}
