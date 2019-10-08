//
// Created by Administrator on 2019/2/11.
//

#include <iostream>

using namespace std;

class A {
public:
    int v;

    A(int n) {
        v = n;
    }

    A(const A &a) {
        v = a.v;
        cout << "copy constructor called" << endl;
    }

};

A a(2);

A func() {
    cout<< "func " << &a << endl;
    return a;
}

/*
 * 需要说明的是，有些编译器出于程序执行效率的考虑，编译的时候进行了优化，函数返回值对象就不用复制构造函数初始化了，这并不符合 C++ 的标准。上面的程序，用 Visual Studio 2010 编译后的输出结果如上所述，但是在 Dev C++ 4.9 中不会调用复制构造函数。把第 14 行的 a 变成全局变量，才会调用复制构造函数。对这一点，读者不必深究。
 */
int main() {

    const A a = func();
    cout<< "main " << &a << endl;

    cout << a.v << endl;


    return 0;
}