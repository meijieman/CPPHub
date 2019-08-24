//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;

class A {
    // 友元类
    friend class B;

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

class B {
public:
    // B 这个友元类可以访问 A 的私有成员
    void accessAny() {
        a.i = 30;
    }

private:
    A a;
};


// 运算符重载，本质还是函数的调用
class Point {
public:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;

    }

    // 成员函数 重载 - 号
    Point operator-(Point &p2) {
        Point tmp(this->x - p2.x, this->y - p2.y);
        return tmp;
    }


    void myprint() {
        cout << x << ", " << y << endl;
    }
};

// 重载 + 号
Point operator+(Point &p1, Point &p2) {
    Point tmp(p1.x + p2.x, p1.y + p2.y);
    return tmp;
}



int main() {

    Point p1(10, 20);
    Point p2(30, 40);

    Point p3 = p1 + p2;
    p3.myprint();

    Point p4 = p1 - p2;
//    p4 = p1.operator-(p2);
    p4.myprint();

    return 0;
}

