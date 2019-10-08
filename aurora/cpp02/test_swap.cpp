//
// Created by Administrator on 2019/8/25.
//

#include <string>
#include <iostream>

using namespace std;

void swap(int &, int &);

void swap_p(int *, int *);

int main() {

    int i1 = 22;
    int i2 = 33;
    cout << "bef i1 " << i1 << ", i2 " << i2 << endl;
    swap(i1, i2);
    cout << "i1 " << i1 << ", i2 " << i2 << endl;
    swap_p(&i1, &i2);
    cout << "i1 " << i1 << ", i2 " << i2 << endl;

    return 0;
}


void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swap_p(int *a, int *b){
    int *tmp = a;
    *a = *b;
    *b = *tmp;
}
