#include <stdio.h>

/*统计行数*/
int main(){
	int c, nl;
	nl = 0;
	printf("please input:\n");
	while((c=getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%d \n", nl);
	return 0;
}


