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
    // �޲ι��캯��
    Teacher(){
        cout << "�޲ι��캯��" << endl;
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
    // ��������
    // ������Ҫ���ͷ�ʱ����������������
  ~Teacher1(){
        cout << "��������" << endl;
    }
    Teacher1(){

    }

    // �������캯��(ֵ����)
    Teacher1(const Teacher1 &obj){
        this->name = obj.name;
        this->age = obj.age;
        cout << "�������캯��" << endl;
    }
};

// ���캯���������������������캯��

/*
 * ǳ��������
 *
 */
int main() {

//    Teacher t1;
//    Teacher t2("jack", 22);


    Teacher1 t;

    Teacher1 tt = t; // ���ÿ������캯��

    return 0;
}

