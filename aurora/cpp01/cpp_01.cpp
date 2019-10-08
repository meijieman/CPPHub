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
 给定一个数组input[]?，如果数组长度n为奇数，则将数组中最大的元素放到?output[]?数组最中间的位置，如果数组长度n为偶数，
 则将数组中最大的元素放到?output[]?数组中间两个位置偏右的那个位置上，然后再按从大到小的顺序，依次在第一个位置的两边，
 按照一左一右的顺序，依次存放剩下的数。?
?例如：input[]?=?{3,?6,?1,?9,?7}???output[]?=?{3,?7,?9,?6,?1};?
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

    // 排序，第一个参数为开始排序的内存位置，第二个参数为结束排序的参数位置
    sort(input, input + count, compare); // sort(begin, end)

    cout << "count = " << count << endl;

    index = count / 2;
    output[index] = input[0]; // 给中间的赋值

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
        output[b--] = input[index++]; // 当 count 为奇数， index 会越界，
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


