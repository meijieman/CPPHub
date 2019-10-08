//
// Created by Administrator on 2019/8/26.
//

#include <string>
#include <iostream>
#include<vector>

using namespace std;

template<class T>
T add(T a, T b) {
    return a + b;
}

template<typename Y>
Y multi(Y a, Y b) {
    return a * b;
}

template<class DRESS>
class Human {
    typedef vector<DRESS> vs; // 定义一种类型的别名

public:
    DRESS dress;
    vs dresss;
    int age;
    string name;
};

int main() {

    int i = add(2, 3);

    cout << "i " << i << endl;
    string s1 = "hello ";
    string s2 = "c++";
    string s = add(s1, s2);
    cout << "s " << s << endl;

    double d = multi(4.0, 5.0);
    cout << "d " << d << endl;

    Human<string> *pHuman = new Human<string>;
    (*pHuman).dress = "hat";
    Human<string> &h = (*pHuman);
    h.age = 22;
    string s0 = h.dresss[0];




    return 0;
}

