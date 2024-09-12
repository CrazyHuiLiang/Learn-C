/*
    信号 <signal.h>
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void on_sig(int sig) {
    printf("on sig %d\n", sig);
}

int main(int argc, char **argv) {
    
    // 注册信号
    signal(SIGABRT, on_sig);
    signal(SIGABRT2, on_sig);
    signal(SIGILL, on_sig);
    signal(SIGINT, on_sig);
    signal(SIGSEGV, on_sig);
    signal(SIGTERM, on_sig);

    // 忽略信号
    signal(SIGABRT, SIG_IGN);
    signal(SIGABRT2, SIG_IGN);

    // 设置为默认行为
    // signal(SIGILL, SIG_DFL);

    // 向程序发送信号
    raise(SIGABRT);
    raise(SIGABRT2);
    raise(SIGILL);
    raise(SIGINT);
    raise(SIGSEGV);
    raise(SIGTERM);
    system("pause");
    return 0;
}
