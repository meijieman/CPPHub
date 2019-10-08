//
// Created by Administrator on 2019/9/4.
//
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <windows.h>

using namespace std;

#define NUM_THREADS 5

struct thread_data {
    int thread_id;
    char *message;
};

void *print_hello(void *arg) {
    struct thread_data *my_data;
    my_data = (struct thread_data *) arg;

    Sleep(2000);
    cout << "thread_id " << my_data->thread_id;
    cout << ", message " << my_data->message << endl;

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct thread_data td[NUM_THREADS];

    int rc;
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        cout << "main() creating thread " << i << endl;
        td[i].thread_id = i;
        td[i].message = (char *) "this is a message";
        rc = pthread_create(&threads[i], NULL, print_hello, &td[i]);
        if (rc) {
            cerr << "create thread err " << rc << endl;
            exit(-1);
        }
    }

    pthread_exit(NULL); // fixme 报错
}
