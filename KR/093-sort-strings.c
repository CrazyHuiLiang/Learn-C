/*
 * <5.6 指针数组以及指向指针的指针>
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000			/* 进行排序的最大文本行数 */

char *lineptr[MAXLINES];		/* 指向文本行的指针数组 */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort2(char *lineptr[], int left, int right);

/* 对输入的文本进行排序 */
int main(int argc, char **argv) {
	int nlines;		/* 读取的输入行数目 */
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort2(lineptr, 0, nlines-1);
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
int readlines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while ((len = getline2(line, MAXLEN)) > 0)
		if (nlines>=maxlines || ((p=(char *)malloc(len)) == NULL))
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
void swap(char *v[], int i, int j) {
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* 按递增顺序对 v[left] ... v[right] 进行排序 */
void qsort2(char *v[], int left, int right) {
	int i, last;
	if (left >= right)  /* 如果数组元素的个数小于 2，则返回 */
		return;
	
	swap(v, left, (left+right)/2);
	last = left;

	for (i = left+1; i<=right; i++) {
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qsort2(v, left, last-1);
	qsort2(v, last+1, right);
}

