//
// Created by Major on 2019/3/20 21:24.
//

#include <iostream>

using namespace std;

void swap_p(int * a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;

}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {

    int j = 20;
    int k = 6;

    swap(j, k);

    cout << j << ", " << k << endl;

    j = 5;
    k = 6;
    swap_p(&j, &k);

    cout << j << ", " << k << endl;

    return 0;

}