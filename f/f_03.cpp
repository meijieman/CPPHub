//
// Created by Administrator on 2019/10/16.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int i = 9;
    int j = 10;

    cout << setw(2) << left << i << "    " << i << endl;
    cout << setw(2) << left << j << "    " << j << endl;


    //8)宽度不足时，负号和数值分列左右，中间用填充字符填充
    cout << setw(12) << left << -12.1 << endl;





    return 0;
}
