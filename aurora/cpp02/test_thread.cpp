//
// Created by Administrator on 2019/9/4.
//

#include <iostream>
#include <pthread.h>

using namespace std;

const int THREAD_NUM = 5;

void *run(void *args) {
    cout << "running... " << endl;

    return nullptr;
}

int main() {

    /*
     * 要支持 pthread，需要在 CMakeLists.txt 中配置
     * find_package(Threads REQUIRED)
     * target_link_libraries(cpp_02_test_thread Threads::Threads)
     */
    pthread_t t = 2;
    int ret = pthread_create(&t, NULL, &run, NULL);
    cerr << "create ret " << ret << endl;

    pthread_exit(NULL);
    return 0;
}
