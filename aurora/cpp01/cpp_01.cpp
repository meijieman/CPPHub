//
// Created by Administrator on 2019/2/1.
//
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

/*
 ����һ������input[]?��������鳤��nΪ������������������Ԫ�طŵ�?output[]?�������м��λ�ã�������鳤��nΪż����
 ������������Ԫ�طŵ�?output[]?�����м�����λ��ƫ�ҵ��Ǹ�λ���ϣ�Ȼ���ٰ��Ӵ�С��˳�������ڵ�һ��λ�õ����ߣ�
 ����һ��һ�ҵ�˳�����δ��ʣ�µ�����?
?���磺input[]?=?{3,?6,?1,?9,?7}???output[]?=?{3,?7,?9,?6,?1};?
?input[]?=?{3,?6,?1,?9,?7,?8}????output[]?=?{1,?6,?8,?9,?7,?3}
 */

int input[100], output[100];

void sort2() {
    int index, a, b, j = 1, count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> input[i];
    }

    cout << "input + count = " << input + count << endl;

    // ���򣬵�һ������Ϊ��ʼ������ڴ�λ�ã��ڶ�������Ϊ��������Ĳ���λ��
    sort(input, input + count, compare); // sort(begin, end)

    cout << "count = " << count << endl;

    index = count / 2;
    output[index] = input[0]; // ���м�ĸ�ֵ

    a = b = index;

    while (j < count) {
        output[--a] = input[j++];
        output[++b] = input[j++];
    }

    for (index = 0; index < count; index++) {
        cout << output[index] << " ";
    }

    cout << endl;
}

void sort3() {
    int input[6] = {3, 7, 2, 4, 1, 6};

    const int count = (sizeof(input) / sizeof(input[0]));

    sort(input, input + count);

    for (int i = 0; i < count; i++) {
        cout << input[i] << " ";
    }
    cout << endl;

    int output[count];
    int a = 0;
    int b = count - 1;
    int index = 0;

    output[count / 2] = input[count -1];

    while (index < count) {
        output[a++] = input[index++];
        output[b--] = input[index++]; // �� count Ϊ������ index ��Խ�磬
    }

    for (int i = 0; i < count; i++) {
        cout << output[i] << " ";
    }
    cout << endl;
}


int main() {

//    sort2();
    sort3();

    return 0;
}


