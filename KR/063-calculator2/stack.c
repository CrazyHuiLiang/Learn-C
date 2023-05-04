#include <stdio.h>
#include "calc.h"
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
