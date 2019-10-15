//
// Created by Administrator on 2019/10/12.
//

#include <ctime>
#include <iostream>

using namespace std;

int main() {

    clock_t startTime,endTime;

    startTime = clock();
    const float x = 1.1;
    const float z = 1.123;
    float y = x;

    for (int i = 0; i < 90000000; ++i) {
        y *= x;
        y /= z;
//        y += 0.1f;
//        y -= 0.1f;

        y += 0.1;
        y -= 0.1;
    }

    endTime = clock();
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    return 0;
}
