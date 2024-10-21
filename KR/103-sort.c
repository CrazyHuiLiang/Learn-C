/*
 *	指向函数的指针
 *
 *	排序程序通常包括 3 部分：
 *		判断任何两个对象之间次序的比较操作
 *		颠倒对象次序的交换操作
 *		一个用于比较和交换对象直到所有对象都按正确次序排列的排序算法
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int(*comp_f)(void *, void *);         /* 排序函数的对比函数 */
#define MAXLINE 5000                          /* 待排序的最大行数 */
char *lineptr[MAXLINE];                       /* 指向文本行的指针数 */


int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort2(void *lineptr[], int left, int right, int (*comp)(void *, void *));


/* 按数值顺序比较字符串 s1 和 s2 */
int numcmp(char *s1, char *s2) {
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

/* 对输入的文本进行排序 */
int main(int argc, char **argv) {
	int nlines;		/* 读取的输入行数目 */
	int numeric = 0;/* 若进行数值排序，则 numeric 的值为 1 */

	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;

	if ((nlines = readlines(lineptr, MAXLINE)) >= 0) {
		// 如果参数中有 -n 则按照数值大小排序，否则按照字节序排序
		// numcmp，strcmp 是函数的地址。因为它们是函数，所以前面不需要加上取地址运算符&
		qsort2((void **)lineptr, 0, nlines-1, (numeric ? (comp_f)numcmp : (comp_f)strcmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: innput too big to sort\n");
		return 1;
	}

	return 0;
}


#define MAXLEN 1000			/* 每个输入文本行的最大长度 */
int getline2(char s[], int lim) {
	int c, i;
	i = 0;
	while (--lim>0 && (c=getchar()) != EOF && c!='\n')
		s[i++] = c;
	if (c=='\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* 读取输入行 */
int readlines(char *lineptr[], int maxLines) {
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while ((len = getline2(line, MAXLEN)) > 0)
		if (nlines>=maxLines || ((p=(char *)malloc(len)) == NULL))
			return -1;
		else {
			line[len-1] = '\0'; /* 删除换行符 */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* 写输出行 */
void writelines(char *lineptr[], int nlines) {
/*
	int i;
	for (i=0; i<nlines; i++) {
		printf("%s\n", lineptr[i]);
	}
*/
	while(nlines-- > 0) {
		printf("%s\n", *lineptr++);
	}
}

/* 交换 v[i] 和 v[j] */
void swap(void *v[], int i, int j) {
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* 按递增顺序对 v[left] ... v[right] 进行排序 */
void qsort2(void *v[], int left, int right, int (*comp)(void *, void *)) {
	int i, last;
	if (left >= right)  /* 如果数组元素的个数小于 2，则返回 */
		return;
	
	swap(v, left, (left+right)/2);
	last = left;

	for (i = left+1; i<=right; i++) {
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	}
	swap((void **)v, left, last);
	qsort2(v, left, last-1, comp);
	qsort2(v, last+1, right, comp);
}

