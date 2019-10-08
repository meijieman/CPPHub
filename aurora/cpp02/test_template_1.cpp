//
// Created by Administrator on 2019/9/4.
//

#include <iostream>
#include <string>

using namespace std;


// 函数模板
template<typename T>
inline T const &Max(T const &a, T const &b) {

    return a < b ? b : a;
}

int main() {

    int i = 39, j = 20;
    cout << "Max int " << Max(i, j) << endl;

    double f1 = 13.5, f2 = 20.7;
    cout << "Max double " << Max(f1, f2) << endl;

    string s1 = "Hello", s2 = "World";
    cout << "Max string " << Max(s1, s2) << endl;

    return 0;
}