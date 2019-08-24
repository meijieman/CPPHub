//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;

// 构造函数的属性初始化列表
class Teacher{
private:
    char* name;
public:
    static int total;

    Teacher(char* name){
        this->name = name;
        cout << "有参构造函数" << endl;
    }
    ~Teacher(){
        cout << "析构函数" << endl;

    }

    char* getName(){
        return this->name;
    }
    void setName(char* name){
        this->name = name;
    }

    // 静态函数
    static void count(){
        total++;
    }
};

class Student{
private:
    int id;
    Teacher t1;
    Teacher t2;

public:
    Student(int id, char *t1_n, char *t2_n)
            : t1(t1_n),
              t2(t2_n) {
        this->id = id;
    }

    void myprint(){
        cout << id << ", " << t1.getName() << ", " << t2.getName() << endl;
    }

    ~Student(){
        cout << "Student 析构函数" << endl;

    }
};


// C++ 写法与 C 写法区别在于 C++ 的会调用构造函数和析构函数，C 的写法不会
void func(){
    // C++
    Teacher *t1 = new Teacher("jack");
    cout << t1->getName() << endl;
    delete  t1; // 手动释放

    // C
    Teacher* t2 = (Teacher* ) malloc(sizeof(Teacher));
    t2->setName("jack");
    free(t2);

}

// static
void func2(){
    Teacher::total++;
    cout << Teacher::total << endl;

    Teacher::count();

    Teacher t1("yuehan");
    t1.count();
}


// 静态属性初始化赋值
int Teacher::total = 9;

int main() {
    Student s1(10, "miss bo", "ms liu");
//    Student s2(20, "jason", "jason");

    s1.myprint();
//    s2.myprint();


    func();


    // C
    int* p1 = (int*) malloc(sizeof(int)*10);
    p1[0] = 0;
    free(p1);

    // C++
    int *p2 = new int[10];
    p2[0] = 2;
    // 释放数组
    delete[] p2;

    func2();

    return 0;
}

