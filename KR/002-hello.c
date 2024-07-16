// 梦开始的地方：打印Hello world
#include <stdio.h>
#include <string.h>

int main(){
	printf("hello world \n\n");
    char c1[] = {'1', '2', '3', '4', '5', '\0'};
    char c2[] = "12345";
    printf("c1 length: %zu, c2 length: %zu\n", strlen(c1), strlen(c2));
	return 0;
}
