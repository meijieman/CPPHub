//
// Created by Administrator on 2019/8/27.
//
#include <iostream>
#include <conio.h>

using namespace std;

class Parent {
public:
    char data[20];

    void Function1();

    virtual void Function2();
} parent;

void Parent::Function1() {
    printf("This is parent, function1\n");
}

void Parent::Function2() {
    printf("This is parent, function2\n");
}

class Child : public Parent {
    void Function1();

    void Function2();
} child;

void Child::Function1() {
    printf("This is child, funciton1\n");
}

void Child::Function2() {
    printf("This is child, function2\n");
}

int main(int argc, char *argv[]) {
    Parent *p;
    printf("please input:");
    if (getch() == 'c') {
        p = &child;
    } else {
        p = &parent;
    }

    p->Function1();
    p->Function2();

    return 0;
}

