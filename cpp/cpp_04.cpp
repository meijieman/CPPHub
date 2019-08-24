//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>
using namespace std;

void swap_1(int *a, int *b){
    // 指针值交换
    int c = 0;
    c = *a;
    *a = *b;
    *b = c;
}

void swap_2(int &a, int &b){
    // 引用交换
    int c = 0;
    c = a;
    a = b;
    b = c;

}

int main(){

    int a = 10;

    int &b = a; // 表示 C++ 中的引用，是 a 所指向内存空间的一个别名
    cout << b << endl;

    int x = 10;
    int y = 20;
    cout << "x = " << x << ", y = " << y << endl;
//    swap_1(&x, &y);
    swap_2(x, y);
    cout << "交换后 x = " << x << ", y = " << y << endl;

    return 0;
}