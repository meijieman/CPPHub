//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;

// ���ú�ָ�������
// ����������ȡ����û�����壬��Ϊ�����������ݣ��ܱ�֤�������ݹ����в���������
// ���ÿ���ֱ�Ӳ���������ָ��Ҫͨ��ȡֵ *p ��Ӳ���������ָ��Ŀɶ�д�Բ�

// ������

void myprintf(const int &a) {
    cout << a << endl;
}

void method(){
    int i = 9;
    // ���ñ�����ֵ������Ϊ��
//    int &a = NULL;

}

struct Teacher{
    char* name;
    int age;
};

void myprint(Teacher &t){
    cout << t.name << ", " << t.age <<endl;

}

int main() {

    // ָ�볣����ָ��ĳ��������ı��ַ��ָ�룬�����޸�ָ�������
    int a = 2, b = 3;
    int *const p1 = &a;
//    p1 = &b;
    *p1 = 4;

    // ����ָ�룬ָ������ָ�룬���ݲ����޸�
    const int *p2 = &a;
    p2 = &b;
//    *p2 = 9;

//    cout << t->name << ", " << t->age << endl;

    Teacher t;
    t.age = 2;


    // ������
    const int &c = 11;

    return 0;
}

