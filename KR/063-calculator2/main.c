/*
编写一个具有加减乘除四则运算功能的计算器程序。

为了实现简单，计算器使用逆波兰表示法代替普通的中缀表示法

逆波兰表示法：每个操作数都依次压入栈中；当一个运算符到达时，从栈中弹出相应数目的操作数（对二元运算符来说是两个操作数），
把该运算符作用于弹出的操作数，并把运算结果再压入到栈中



gcc main.c getop.c getch.c stack.c
./a.out
*/
#include <stdio.h>
#include <stdlib.h>       // 为了使用 atof() 函数
#include "calc.h"
#define MAXOP 100         // 操作数或运算符的最大长度


// 逆波兰计算器
int main(int argc, char *argv[]) {
	int type;
	double op2;			// 第二个操作数（减法、除法不满足交换率，需要先将第二个操作数弹出保存）
	char s[MAXOP];
	
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER: {
				push(atof(s));
			} break;
			case '+': {
				push(pop() + pop());
			} break;
			case '*': {
				push(pop() * pop());
			} break;
			case '-': {
				op2 = pop();
				push(pop() - op2);
			} break;
			case '/': {
				op2 = pop();
				if (op2 == 0.0) {
					printf("Error: zero divisor\n");
					return 1;
				}
				push(pop() / op2);
			} break;
			case '\n': {
				printf("\t%.8g\n", pop());
			} break;
			default: {
				printf("Error: unknown command %s\n", s);
			} break;
		}
	}
}
