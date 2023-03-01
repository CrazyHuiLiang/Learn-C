/*
	expand(s1, s2) 将字符串s1中类似a-z一类的速记符号在字符串s2中扩展为等价的完整列表abc...xyz
	作为前导和尾随的-原样输出
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void expand(char *s1, char *s2) {
	int length = strlen(s1);	// s1的长度
	char c1,c2,c3; 				// 使用3个字符指向字符串中连续的3个位置，类似一个长度为3的滑动窗口
	int i;						// 指向窗口起点（c1）的位置

	if (length<3) { 			// 如果s1长度小于3，不可能存在区间模式，直接返回
		s2 = strcpy(s2, s1);
		return;
	}
	for (i = 0; i<length;) {	// 窗口移动到最后一个字符
		c1 = *(s1+i);
		c2 = *(s1+i+1);
		*s2++ = c1;				// 将三个字符中的第一个直接拷贝到s2中
		if (c2 == '\0') {		// 如果c2指向字符串结尾的\0，证明扫描已结束
			break;
		}
		if(c2 != '-') {			// 如果三个元素的中间元素不是-
			i++; 				// 窗口向后移动一位
			continue;
		}

		c3 = *(s1+i+2);
		if (c3 == '\0') {		// 如果c3指向字符串结尾的\0，证明c2已是最后一个字符
			*s2++ = c2;			// 将c2拷贝到s2中后，扫描任务就已结束
			break;
		}
		if (c1 >= c3) {			// 如果中间元素是-，但是c1不小于c3，也不符合区间返回的规范
			*s2++ = c2;			// 将第二个字符-，复制到s2
			i += 2;				// 此时窗口直接向后移动2个位置
			continue;
		}
		while (++c1 < c3) {		// 经过前面情况的过滤，可以断定此时的三个字符表示一个区间
			*s2++ = c1;			// 扩展区间内的字符, 值区间：[c1+1, c3)
		}
		i+=2;					// 窗口向后移动2个位置
	}
	*s2++ = '\0';
}

int main(int argc, char *argv[]) {
	char *s1 = "---123456a-z123456-9-";
	char *s2 = calloc(sizeof(char), 100);
	expand(s1, s2);
	printf("%s\nDone", s2);
	return 0;
}