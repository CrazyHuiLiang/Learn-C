#include <stdio.h>
/*文件复制， 
control + D 结束一次输入（等于输入EOF）
control + C 结束程序进程
*/
int main(){
    int c;
    c = getchar();
    while( c!=EOF){
        putchar(c);
        c = getchar();
    }
    return 0;
}
