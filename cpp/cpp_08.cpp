//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;

struct Teacher{
    char name[20];
    int age;
};


/*
 引用是变量的别名

 */
int main() {

    Teacher t;

    Teacher &t1 = t; // 引用
    Teacher *p = &t; // 指针

    cout << sizeof(t1) << endl;
    cout << sizeof(p) << endl;


    return 0;
}

