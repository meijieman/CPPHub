//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>
using namespace std;

struct Teacher {
 char* name;
 int age;
};

// ���õ���Ҫ���ܣ���Ϊ�����Ĳ����򷵻�ֵ
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

    // ���ʹ��ָ��ͱȽ��鷳
    myprint2(&t);

    return 0;
}