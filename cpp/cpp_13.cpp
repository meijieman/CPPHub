//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;


class A {
    // 友元函数
    friend void modify_i(A *p, int a);
private:
    int i;
public:
    A(int i) {
        this->i = i;
    }

    void myprint() {
        cout << i << endl;
    }
};

// 友元函数的实现，在友元函数可以访问私有的属性
void modify_i(A *p, int a) {
    p->i = a;
}


int main() {
    A *a = new A(10);
    a->myprint();

    modify_i(a, 20);
    a->myprint();


    return 0;
}

