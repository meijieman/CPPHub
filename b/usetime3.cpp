//
// Created by Major on 2019/4/6 12:53.
//

#include <iostream>
#include "mytime3.h"

int main(){

    using std::cout;
    using std::endl;

    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida and Tosca:\n";
    cout << aida << ", " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
    cout << "10.0 * Tosca: " << 10.0 * tosca - 2 << endl; // 不是结果所料


    return 0;
}
