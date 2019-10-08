//
// Created by Administrator on 2019/9/4.
//

#include <iostream>
#include <csignal>

#if _WIN32_WINNT

#include <windows.h>

#elif
#include <unistd.h>
#endif

using namespace std;


void signalHandler(int signum) {
    cout << "interrupt signal (" << signum << ") received." << endl;

    exit(signum);
}

int main() {
    signal(SIGINT, signalHandler);

    while (1) {
        cout << "going to sleep" << endl;
#if _WIN32_WINNT
        cout << "win" << endl;
        Sleep(1000);
#elif
        cout << "linux" << endl;
        sleep(1);
#endif
    }


    return 0;
}