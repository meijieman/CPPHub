//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;

// 当属性私有时，通过友元函数来完成运算符重载
class Point {

    friend Point operator+(Point &p1, Point &p2);

private:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    void myprint() {
        cout << x << "," << y << endl;
    }
};

Point operator+(Point &p1, Point &p2) {
    Point tmp = Point(p1.x + p2.x, p1.y + p2.y);
    return tmp;
}

int main() {
    Point p1(10, 20);
    Point p2(30, 40);

    Point p3 = p1 + p2;
    p3.myprint();

    return 0;
}

