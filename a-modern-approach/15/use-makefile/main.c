/*
	程序代码被拆分至两个文件中，main.c 和 mylib.c，编译方式有：
		* 可以使用gcc直接指明被编译的文件 gcc -o a.out main.c mylib.c
		* 可以使用makefile， 执行make命令即可
*/
#include "mylib.h"

int main() {
	helloworld();
	return 0;
}
