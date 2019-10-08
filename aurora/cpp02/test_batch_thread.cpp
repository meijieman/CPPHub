//
// Created by Administrator on 2019/9/5.
//



#include <iostream>
#include <windows.h>
#include <pthread.h>

using namespace std;


void *run(void *args) {

    cout << "running... " << endl;
    Sleep(1000);
//
    cout << "running exit " << endl;
//    pthread_exit(nullptr);
    cout << "running exit2 " << endl;

    return nullptr;

}


int main() {

    pthread_t tid;
    cout << "tid " << tid << endl;

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    int rst = pthread_create(&tid, &attr, run, nullptr);

    if (rst) {
        cout << "error " << rst << endl;
        return -1;
    }

//    pthread_join(tid, nullptr);
    cout << "main end... " << endl;

    pthread_exit(nullptr);

}
