//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>
using namespace std;

struct Teacher {
 char* name;
 int age;
};

// 引用的主要功能：作为函数的参数或返回值
void myprint(Teacher &t){
    cout << t.name <<", " << t.age << endl;
    t.age = 22;
}


void myprint2(Teacher *t){
    cout<< t->name << ", " << t->age << endl;
    (*t).age = 33;
}

int main(){
    Teacher t = {"major", 27};
//    t.name = "Jason";
//    t.age = 20;

    myprint(t);

    // 如果使用指针就比较麻烦
    myprint2(&t);

    return 0;
}