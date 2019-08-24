//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;

class Person {

};

class Citizen {

};

// 多继承
class Student : public Person, public Citizen {

};

// 继承的二义性

class A {
public:
    char *name;
};

// 虚继承，不同路径继承来的同名成员只有一份拷贝，解决不明确的问题
class A1 : virtual public A {

};

class A2 : virtual public A {

};

class B : public A1, public A2 {

};


// 虚函数
// 虚函数主要用于多态，多态用于解决程序的扩展性

int main() {

    B b;
    b.name = "major";

    cout<< b.name << endl;
    // 显式调用
//    b.A1:name = "m1";



    return 0;
}

