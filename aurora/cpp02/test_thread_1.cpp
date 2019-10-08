//
// Created by Administrator on 2019/9/4.
//

#include <iostream>
#include <pthread.h>

using namespace std;

#define THREAD_NUM  5

void *say_hello(void *args) {
    cout << "Hello " << endl;
    return nullptr;
}

int main() {
    pthread_t tids[THREAD_NUM];
    for (int i = 0; i < THREAD_NUM; i++) {
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if (ret != 0) {
            cerr << "pthread create error " << ret << endl;
        }
    }

    pthread_exit(NULL);
    return 0;
}