//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;

struct Teacher{
    char name[20];
    int age;
};


/*
 �����Ǳ����ı���

 */
int main() {

    Teacher t;

    Teacher &t1 = t; // ����
    Teacher *p = &t; // ָ��

    cout << sizeof(t1) << endl;
    cout << sizeof(p) << endl;


    return 0;
}

