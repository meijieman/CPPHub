//
// File: 02.cpp
// Created by Major on 2019/8/24 10:32.
//

#include <iostream>

using namespace std;

void think();

void think_twice();

void process(void (*th)());

double pam(int i);

void estimate(int lines, double (*pf)(int));

int main() {
    // 函数指针
    void (*fun)() = think;
    cout << fun << endl;
    fun(); // 实际调用的是 think()

    double (*pf)(int); // pf 是函数指针，指向 返回类型为 double，参数列表为int 的函数
    pf = pam;

    estimate(20, pf);
    estimate(20, pam);

    process(think); // 入参为 think 函数
    process(think_twice); // 入参为 think_twice 函数

/*
 * 函数指针类似于java 的面向接口编程，只是 java 中方法的输入参数为类级别，而 cpp 的为 函数级别
 */



    // 指针函数 指的是返回类型为指针的函数


}

void think() {
    cout << "think" << endl;
}

void think_twice() {
    cout << "think twice" << endl;
}

void process(void (*th)()) {
    cout << "start" << endl;
    (*th)();
    cout << "end" << endl;


}

double pam(int i) {
    cout << "pam " << i << endl;

    return 2.3 * i;
}

// 输入参数含有函数指针的函数
void estimate(int lines, double (*pf)(int)) {
    double total = (*pf)(lines);
    cout << "estimate total " << total << endl;
}
