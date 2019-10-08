//
// Created by Administrator on 2019/9/4.
//
/*C++ 信号处理
SIGABRT	程序的异常终止，如调用 abort。
SIGFPE	错误的算术运算，比如除以零或导致溢出的操作。
SIGILL	检测非法指令。
SIGINT	接收到交互注意信号。
SIGSEGV	非法访问内存。
SIGTERM	发送到程序的终止请求。
 */

#include <iostream>
#include <csignal>
#include <windows.h>

using namespace std;

void signalHandler(int signum) {
    cout << "interrupt signal (" << signum << ") received." << endl;

    exit(signum);
}

int main() {
    int i = 0;
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);

    while (++i) {
        cout << "going to sleep" << endl;
        if (i == 3) {
            // 生成信号
            raise(SIGINT);
        }

        Sleep(1000);
    }

    return 0;
}