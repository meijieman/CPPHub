//
// Created by Administrator on 2019/8/25.
//
#include <string>
#include <iostream>

using namespace std;

struct result {
    int code;
    string msg;
};

struct {
    int code;
    string msg;
} def = {0, "not define"};


struct data {
    string b;
} data1, data2;


int main() {

    result success = {200, "ok"};
    cout << "success.msg " << success.msg << endl;

    cout << "def.code " << def.code << endl;

    cout << data1.b << " " << data2.b << endl;


    return 0;
}