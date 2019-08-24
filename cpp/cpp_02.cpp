//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>
using namespace std;


struct MyTeacher{

private:
    char name[20];
public:
    int age;
public:
    void say(){
        cout << this->age << " old" << endl;
    }

};

int main(){
    // 类可以继承，结构体不能
    MyTeacher t1;
    struct MyTeacher t2;
    t1.age= 20;
    t1.say();


    return 0;
}