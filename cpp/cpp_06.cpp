//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;

struct Teacher {
    char *name;
    int age;
};

void getTeacher(Teacher **p) {
    cout<<"getTeacher1111"<< endl;

    Teacher *tmp = (Teacher *) malloc(sizeof(Teacher));
    tmp->age = 20;
    tmp->name = "ear";
    *p = tmp;
}

// 指针的引用，代替二级指针
void getTeacher(Teacher* &p) {
    cout<<"getTeacher222"<< endl;
    p = (Teacher *) malloc(sizeof(Teacher));
    p->age = 20;
    p->name = "aaa";
}

int main() {

    Teacher *t = NULL;
    getTeacher(t);
    cout << t->name << ", " << t->age << endl;
    getTeacher(&t);

    cout << t->name << ", " << t->age << endl;

    return 0;
}