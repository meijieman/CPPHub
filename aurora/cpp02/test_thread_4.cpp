//
// Created by Administrator on 2019/9/4.
//

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <windows.h>

using namespace std;

#define NUM_THREADS 5

void *wait(void *t) {
    int i;
    long tid;
    tid = *((int *) t);
    Sleep(1000);

    cout << "sleeping in thread " << endl;

    pthread_exit(NULL);
}

int main() {
    int rc;
    int i;
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    void *status;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (int i = 0; i < NUM_THREADS; i++) {
        cout << "main() createing thread " << i << endl;
        rc = pthread_create(&threads[i], NULL, wait, (void *) &i);
        if (rc) {
            cout << "error " << rc << endl;
            exit(-1);
        }
    }

    pthread_attr_destroy(&attr);
    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], &status);
        if (rc) {
            cout << "error " << i << ", " << status << endl;
            exit(-1);
        }
        cout << "main() completed. id " << i << ", status " << status << endl;
    }

    cout << "exit " << endl;

    pthread_exit(NULL);

    return 0;
}


