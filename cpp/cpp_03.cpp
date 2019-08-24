//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>
using namespace std;


int main(){
    // C++ 多了个 bool 类型
    bool  b = true;
    bool  b1 = -15; // 不等于 0 的都表示 true

    if(b1){
        cout << "yes" << endl;
        cout << sizeof(bool) << endl;
    } else{
        cout << "no" << endl;
    }

    int aa = 10, bb = 20;
    cout << ((aa > bb) ? aa : bb) << endl;

    // 三目运算符左值可以赋值
    ((aa > bb) ? aa : bb) = 30;
    cout << "the value is " << bb << endl;

    return 0;
}