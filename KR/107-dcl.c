/*
    复杂声明，将声明转换为文字描述
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);
int tokentype;          /* 最后一个记号的类型 */
char token[MAXTOKEN];   /* 最后一个记号字符串 */
char name[MAXTOKEN];    /* 标识符名 */
char datatype[MAXTOKEN];/* 数据类型为 char、int 等 */
char out[1000];         /* 输出串 */

#define BUFSIZE 100
char buf[BUFSIZE];		/* 用于ungetch函数的缓冲区 */
int bufp = 0;			/* buf中下一个空闲位置 */


/* 将声明转换为文字描述 */
int main(int argc, char **argv) {
    while(gettoken() != EOF) { /* 该行的第一个记号是数据类型 */
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();                  /* 分析该行的其余部分 */
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}
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

/* 跳过空格和制表符，返回下一个标记 */
int gettoken(void) {
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    while((c = getch()) == ' ' || c == '\t'){}

    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']';) {}
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else 
        return tokentype = c;
}

/* 对一个声明符进行语法分析 */
void dcl(void) {
    int ns;
    for (ns = 0; gettoken() == '*'; ) /* 统计字符 * 的个数 */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

/* 分析一个直接声明 */
void dirdcl(void) {
    int type;
    if (tokentype == '(') { /* 形式为 (dcl) */
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    } else if (tokentype == NAME) /* 变量名 */
        strcpy(name, token);
    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS) 
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

