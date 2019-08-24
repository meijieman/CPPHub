//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>
#include <stdarg.h>

using namespace std;


class Teacher{
private:
    char* name;
    int age;
public:
    // 无参构造函数
    Teacher(){
        cout << "无参构造函数" << endl;
    }

    Teacher(char* name, int age){
        this->name = name;
        this->age = age;
    }
};

class Teacher1{
private:
    char* name;
    int age;
public:
    // 析构函数
    // 当对象要被释放时，析构函数被调用
  ~Teacher1(){
        cout << "析构函数" << endl;
    }
    Teacher1(){

    }

    // 拷贝构造函数(值拷贝)
    Teacher1(const Teacher1 &obj){
        this->name = obj.name;
        this->age = obj.age;
        cout << "拷贝构造函数" << endl;
    }
};

// 构造函数、析构函数、拷贝构造函数

/*
 * 浅拷贝问题
 *
 */
int main() {

//    Teacher t1;
//    Teacher t2("jack", 22);


    Teacher1 t;

    Teacher1 tt = t; // 调用拷贝构造函数

    return 0;
}

