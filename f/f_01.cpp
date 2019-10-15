//
// Created by Administrator on 2019/10/12.
//
#include <iostream>

using namespace std;

void func0();

void func();

int main() {

    cout << "hello" << endl;

//    func0();
    func();


    return 0;
}

void func0() {
    const int a = 1;
    int const b = 2; // a, b 没有区别，即 const int 和 int const 没有区别

    const int *c = &a; // 指向常整型数的指针，整型数不可修改（不能通过*c 来对 a 重新赋值），但指针可以
//    *c = 2;
    int const *j = &a; // 同 const int * 没有区别
    int d = 3;
    int *const e = &d; // 指向整型数的常指针，整型数可以修改，但指针不行
    int f = 4;
//    e =  &f;
    c = &f;
    f = 40;
    cout << "c " << *c << endl;

    const int *g = &f;
    f = 400;
    g = &d;
    cout << "g " << *g << endl;


    const int *const h = &f; // 指向常整型数的常指针
//    h = &d;
    f = 232;


    int *const pi = &f; // 指针常量，指针不能重新赋值
//    pi = &d;
    *pi = 220;

    const int *pi_1 = &f; //
    pi_1 = &d;
//    *pi_1 = 23;

    const int *const pi_2 = &f;
//    pi_2 = &d;
//    pi_2 = 22;
}

void func() {
//    const int i1 = 40;
    int i1 = 40;

    int *pi;
    pi = &i1;
    *pi = 2;

    cout << "i1 " << i1 << ", pi " << *pi << endl;

    i1 = 33;
    cout << "i1 " << i1 << ", pi " << *pi << endl;

    const int *const pii = &i1;

    cout << "i1 " << i1 << ", pii " << *pii << endl;

}