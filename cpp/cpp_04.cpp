//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>
using namespace std;

void swap_1(int *a, int *b){
    // ָ��ֵ����
    int c = 0;
    c = *a;
    *a = *b;
    *b = c;
}

void swap_2(int &a, int &b){
    // ���ý���
    int c = 0;
    c = a;
    a = b;
    b = c;

}

int main(){

    int a = 10;

    int &b = a; // ��ʾ C++ �е����ã��� a ��ָ���ڴ�ռ��һ������
    cout << b << endl;

    int x = 10;
    int y = 20;
    cout << "x = " << x << ", y = " << y << endl;
//    swap_1(&x, &y);
    swap_2(x, y);
    cout << "������ x = " << x << ", y = " << y << endl;

    return 0;
}