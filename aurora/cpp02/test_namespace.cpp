//
// Created by Administrator on 2019/9/4.
//
#include <iostream>

//using namespace std;
using std::cout;
using std::endl;

namespace first_space{
    void func(){
        cout << "inside first_space" << endl;
    }
}

namespace second_space{
    void func(){
        cout << "inside second_space" << endl;
    }
}

using namespace second_space;

int main() {

    first_space::func();

    second_space::func();

    func();


    return 0;
}
