//
// Created by Administrator on 2019/8/28.
//
#include <string>
#include <iostream>

using namespace std;

class Parent {
public:
    virtual void print(string str);

} parent;

void Parent::print(string str) {
    cout << "parent " << str << endl;
}


class Child : public Parent {
public:
    virtual void print(string str);

} child;

void Child::print(string str) {
    cout << "child " << str << endl;
}


int main() {

    Parent p = Child();
    p.print("aha");

    Parent p1 = child;
    p1.print("good");

    Parent *pp = new Child();
    pp->print("eeeeee");
    delete pp;

    Parent *pp1 = &child;
    (*pp1).print("dddd");

    // child 在什么时候销毁？

}

