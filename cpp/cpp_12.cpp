//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;

class A{
public:
    int i;
    int j;
    int k;

    static int m;
};

class B {
public:
    int i;
    int j;
    int k;

    // ����ָ��
//    void(*myprintf)() = myprintf;

    void myprintf() {
        cout << "myprintf" << endl;
    }
};

int main() {

    // C/C++ �ڴ������ջ���ѣ� ȫ�֣���̬��ȫ�֣������������ַ������� ���������
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;

    return 0;
}

