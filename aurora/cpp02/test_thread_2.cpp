//
// Created by Administrator on 2019/9/4.
//

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <windows.h>

using namespace std;

#define NUM_THREADS  5


void *print_hello(void *thread_id){
    int tid = *((int *) thread_id);
    cout << "running... id " << tid << endl;
    Sleep(1000);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    int indexes[NUM_THREADS];
    int rc;
    int i;

    for(i = 0; i < NUM_THREADS; i ++){
        cout << "main " << i << endl;
        indexes[i] = i;
        rc = pthread_create(&threads[i], NULL, print_hello, (void *) & (indexes[i]));

        if(rc){
            cerr << "create fail. " << rc << endl;
            exit(-1);
        }
    }

    pthread_exit(NULL);
}