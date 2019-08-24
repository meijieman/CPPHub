//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;

class A{
public:
    int i;
    int j;
    int k;

    static int m;
};

class B {
public:
    int i;
    int j;
    int k;

    // 函数指针
//    void(*myprintf)() = myprintf;

    void myprintf() {
        cout << "myprintf" << endl;
    }
};

int main() {

    // C/C++ 内存分区：栈，堆， 全局（静态，全局），常量区（字符串）， 程序代码区
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;

    return 0;
}

