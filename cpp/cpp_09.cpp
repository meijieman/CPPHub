//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>
#include <stdarg.h>

using namespace std;

// ���� Ĭ�ϲ���
void myprint(int x = 10) {
    cout << x << endl;
}

// �ɱ����
void func(int i, ...) {
    va_list args_p;
    va_start(args_p, i);

    int a = va_arg(args_p, int);
    int b = va_arg(args_p, int);
    int c = va_arg(args_p, int);
    int d = va_arg(args_p, int);

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;

    va_end(args_p);

}


int main() {
    func(1, 2, 3);

//    myprint();


    return 0;
}

