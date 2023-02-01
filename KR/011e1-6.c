#include <stdio.h>
// 验证 getchar()!= EOF 的值是0还是1
int main(){

	int c;
	while ((c = getchar()!= EOF)) {
		printf("%d", c);
	}
	printf("\nc==EOF:%d", c); // 通过打印可知 getchar()!= EOF 值为0
	printf("\n\n-------\n");
	return 0;
}

