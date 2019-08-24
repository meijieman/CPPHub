//
// Created by Major on 2019/4/20 9:36.
//

#include <iostream>

using namespace std;

int main(){

    int i = 0;
    for(;;){
        if(i > 100){
            break;
        }
        i++;
        cout << "loop " << i << endl;
    }

    return 0;
}