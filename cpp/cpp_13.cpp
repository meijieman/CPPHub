//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;


class A {
    // ��Ԫ����
    friend void modify_i(A *p, int a);
private:
    int i;
public:
    A(int i) {
        this->i = i;
    }

    void myprint() {
        cout << i << endl;
    }
};

// ��Ԫ������ʵ�֣�����Ԫ�������Է���˽�е�����
void modify_i(A *p, int a) {
    p->i = a;
}


int main() {
    A *a = new A(10);
    a->myprint();

    modify_i(a, 20);
    a->myprint();


    return 0;
}

