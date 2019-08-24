//
// File: 01.cpp
// Created by Major on 2019/8/24 8:57.
//
#include <iostream>
#include <vector>
#include <array>

using namespace std;

struct man {
    string name;
    int age;
    char first;
};

struct {
    int a;
    float b;

    void tostring() {
        cout << a << ", " << b << endl;
    }
} ret_val = {100, 0};

void test_vector();

void test_array();

enum WeekDay {
    MONDAY = 1, TUESDAY, WEDNESDAY
};

void input(WeekDay wd) {
    cout << wd << endl;
}

void p_input(const WeekDay *p) {
    cout << *p << endl;
}


int main() {

    man m = {"major", 22, 's'};
    cout << m.name << endl;
    cout << m.age << endl;
    cout << m.first << endl;

//    ret_val = {200, 0.2};
    ret_val.tostring();

    cout << "==========" << endl;
    input(MONDAY);
    input(TUESDAY);

    WeekDay wd = WEDNESDAY;
    p_input(&wd);
    wd = MONDAY;
    p_input(&wd);

    {
        int i = 9;
        int *p_i = new int;
        p_i = &i;

        cout << "p_i " << p_i << endl;
        cout << "p_i " << *p_i << endl;

//        delete p_i; // 不能够调用 delete， delete 只能释放 new 分配的内存
    }

    {
        int *p_i = new int;
        *p_i = 12;

        cout << "p_i " << p_i << endl;
        cout << "p_i " << *p_i << endl;

        delete p_i; // 需要调用 delete
    }


    man *p_man = new man;
    p_man->name = "xiaoxiao";
    p_man->age = 10;

    cout << p_man->name << endl;
    cout << p_man->age << endl;

    delete p_man; // 需要调用 delete

    man many_man[3]; // 数组保存的是对象
    man *many_man_1[2]; // 数组保存的是对象的地址
//    man[] * p_many_man; // C++17 支持

    many_man[0] = man{};

    many_man_1[0] = new man;

    test_vector();
    test_array();

    return 0;
}

void test_vector() {// 使用 vector（相当于 java 的 queue）替代 数组，避免内存管理，可以动态修改内存大小
//    vector<man> mans(2);
    vector<man> mans;
    man m1 = {"eeee", 231};
    mans[0] = m1;
    cout << mans[0].name << endl;


    auto iterator = mans.begin();

    mans.push_back(m1);
    mans.pop_back();

}


void test_array() {// array 相当于 java 的 list，但是长度固定，保存于栈中，效率与数据差不多
    man m = {};
    array<man, 3> man_arr = {
            m, m
    };// 声明包含 3 个 man 结构体的 array

    man_arr[2] = m;

    cout << man_arr[0].first << endl;

    auto pMan = man_arr.begin();

}
