#include <iostream>

using namespace std;

int main() {
//    std::cout << "Hello, World!" << std::endl;
    cout << "Hello, World!" << endl;

    cout << "aha " << endl;

    bool b;
    char c;
    int i;
    signed int si;
    unsigned int ui;
    short int si2;
    long int li;
    float f;
    double d;
    wchar_t wt;


    int fib[9] = {0, 1, 1};

    for (int index = 0; index < 9; index++) {
        cout << index << " -> " << fib[index] << endl;
    }


    int i1 = 222;
    int *pint;
    pint = &i1;

    cout << i1 << " &i1 " << pint << endl;
    *pint = *pint + 1;
    cout << i1 << " &i1 " << pint << endl;

    return 0;
}


