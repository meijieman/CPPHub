//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;

class Person {

};

class Citizen {

};

// ��̳�
class Student : public Person, public Citizen {

};

// �̳еĶ�����

class A {
public:
    char *name;
};

// ��̳У���ͬ·���̳�����ͬ����Աֻ��һ�ݿ������������ȷ������
class A1 : virtual public A {

};

class A2 : virtual public A {

};

class B : public A1, public A2 {

};


// �麯��
// �麯����Ҫ���ڶ�̬����̬���ڽ���������չ��

int main() {

    B b;
    b.name = "major";

    cout<< b.name << endl;
    // ��ʽ����
//    b.A1:name = "m1";



    return 0;
}

