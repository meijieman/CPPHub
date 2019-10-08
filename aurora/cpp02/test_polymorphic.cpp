//
// Created by Administrator on 2019/9/4.
//
// 多态

#include <iostream>

using namespace std;

class Shape {
protected:
    int width, height;
public:
    Shape(int a = 0, int b = 0) {
        width = a;
        height = b;
    }

    virtual int area() {
        cout << "parent class area " << endl;
        return 0;
    }

    // pure virtual function
//    virtual int area() = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(int a = 0, int b = 0) : Shape(a, b) {

    }

    int area() {
        cout << "rectangle class area " << endl;
        return width * height;
    }

};

class Triangle : public Shape {
public:
    Triangle(int a = 0, int b = 0) : Shape(a, b) {

    }

    int area() {
        cout << "triangle class area " << endl;
        return (width * height) / 2;
    }

};
/*
 虚函数：是在基类中使用关键字 virtual 声明的函数。需要给出实现
 纯虚函数：在基类中定义虚函数，以便在派生类中重新定义该函数更好地适用于对象，但是在基类中又不能对虚函数给出有意义的实现，这个时候就会用到纯虚函数。
    纯虚函数是通过在声明中使用 "= 0" 来指定的
 */

int main() {

    Shape *shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);

    shape = &rec;
    shape->area();

    shape = &tri;
    shape->area();

    return 0;
}



