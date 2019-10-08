#include <iostream>

using namespace std;

void printf(int a) {
    cout << "lalalal " << a << endl;
}

int main() {

    std::cout << "Hello, World!" << std::endl;

    cout << "ahahah" << endl;


    int a;
    a = 100;
    int c = 2;

    int &b = a;

    printf(a);

    cout << b << endl;


    return 0;
}