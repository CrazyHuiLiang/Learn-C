#include <stdio.h>

/*统计行数*/
int main(){
	int c, nl;
	nl = 0;
	printf("please input:\n");
	while((c=getchar()) != EOF)
		if (c == '\n') // 标准库保证输入文件流以行序列的形式出现，每一行均以换行符结束
			++nl;
	printf("%d \n", nl);
	return 0;
}


