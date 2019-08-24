//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;

// 引用和指针的区别
// 单纯给变量取别名没有意义，作为函数参数传递，能保证参数传递过程中不产生副本
// 引用可以直接操作变量，指针要通过取值 *p 间接操作变量，指针的可读写性差

// 常引用

void myprintf(const int &a) {
    cout << a << endl;
}

void method(){
    int i = 9;
    // 引用必须有值，不能为空
//    int &a = NULL;

}

struct Teacher{
    char* name;
    int age;
};

void myprint(Teacher &t){
    cout << t.name << ", " << t.age <<endl;

}

int main() {

    // 指针常量，指针的常量，不改变地址的指针，但可修改指向的内容
    int a = 2, b = 3;
    int *const p1 = &a;
//    p1 = &b;
    *p1 = 4;

    // 常量指针，指向常量的指针，内容不能修改
    const int *p2 = &a;
    p2 = &b;
//    *p2 = 9;

//    cout << t->name << ", " << t->age << endl;

    Teacher t;
    t.age = 2;


    // 常引用
    const int &c = 11;

    return 0;
}

