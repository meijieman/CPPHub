//
// Created by Major on 2019/1/25 23:12.
//
#include <iostream>

using namespace std;

// ģ����
template<class T>
class A {
public:
    A(T a) {
        this->a = a;
    }

protected:
    T a;
};

// �̳�ģ����
class B : public A<int> {
public:
    B(int a, int b) : A<int>(a) {
        this->b = b;
    }

private:
    int b;
};

// ģ����̳�ģ����
template<class T>
class C : public A<T> {
public:
    C(T c, T a) : A<T>(a) {
        this->c = c;
    }

protected:
    T c;
};

int main() {


    return 0;
}









