/*
编写一个具有加减乘除四则运算功能的计算器程序。

为了实现简单，计算器使用逆波兰表示法代替普通的中缀表示法

逆波兰表示法：每个操作数都依次压入栈中；当一个运算符到达时，从栈中弹出相应数目的操作数（对二元运算符来说是两个操作数），
把该运算符作用于弹出的操作数，并把运算结果再压入到栈中
*/
#include <stdio.h>
#include <stdlib.h>       // 为了使用 atof() 函数
#include <ctype.h>


/*     stack start      */
//#include "stack.c"
#define MAXVAL (100)		/* 栈val的最大深度 */
int sp = 0;					/* 下一个空闲栈位置 */
double stack[MAXVAL];		/* 栈 */

/* push函数：把f压入到栈 */
void push(double f) {
	if (sp < MAXVAL) {
		stack[sp++] = f;
	} else {
		printf("Error: stack full, can't push %g\n", f);
	}
}

/* pop函数：弹出并返回栈顶的值 */
double pop(void) {
	if (sp > 0) {
		return stack[--sp];
	}
	printf("Error: stack empty\n");
	return 0.0;
}
/*     stack end      */



#define MAXOP 100         // 操作数或运算符的最大长度
#define NUMBER '0'        // 标识找到一个数

int getop(char []);

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


#define BUFSIZE 100

char buf[BUFSIZE];		/* 用于ungetch函数的缓冲区 */
int bufp = 0;			/* buf中下一个空闲位置 */

/* 取一个字符（可能是压回的字符） */
int getch(void) {
	return (bufp >0) ? buf[--bufp] : getchar();
}


/* 把字符串压回输入中 */
void ungetch(int c) {
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	} else {
		buf[bufp++] = c;
	}
}


/* getop函数：获取下一个运算符或数值操作数 */
int getop(char s[]) {
	int i, c;
	// 需要跳过空格和制表符
	while ((s[0] = c = getch()) == ' ' || c == '\t') {
	}
	
	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		return c;			/* 不是数 */
	}
	
	i = 0;
	if (isdigit(c)) {		/* 收集整数部分 */
		while (isdigit(s[++i] = c = getch())) {
		}
	}
	
	if (c == '.') {
		while (isdigit(s[++i] = c = getch())) {
		}
	}
	s[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}
