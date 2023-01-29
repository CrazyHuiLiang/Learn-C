#include <stdio.h>
// 验证 getchar()!= EOF 的值是0还是1
int main(){

	int c;
	while ((c = getchar()!= EOF)) {
		printf("%d", c);
	}
	return 0;
}

