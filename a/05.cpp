//
// Created by Major on 2019/1/25 23:12.
//
#include <iostream>

using namespace std;


// 类型转换
// static_cast
// const_cast
// dynamic_cast
// reinterpret_cast

void func2(char *c_p) {
    cout << *c_p << endl;

}

void func(const char c[]) {
//    c[1] = 'a';
    // 通过指针间接赋值
//    char *c_p = (char *) c;
    char *c_p = const_cast<char *>(c);
    c_p[1] = 'a';
    cout << c << endl;

}

class Person {
public:
    virtual void print() {
        cout << "person" << endl;
    }
};

class Man : public Person {
public:
    void print() {
        cout << "man" << endl;
    }
};

class Woman : public Person {
public:
    void print() {
        cout << "woman" << endl;
    }
};

void func(Person *obj) {
    obj->print();

}

int main() {


    int i = 0;
    double d = i;

    double d1 = 9.8;
    int j = d1;
    cout << j << endl;
    int k = static_cast<int>(d1);
    cout << k << endl;

    int l = 9;
    int *l_p = &l;


    return 0;
}









