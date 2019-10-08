//
// Created by Administrator on 2019/8/26.
//
#include <string>
#include <iostream>

using namespace std;

struct result {
    int code;
    string msg;
};


result get_result(string &input);

result &get_result(result &src, string &input);

int main() {
    int i;
    // typeid 获取变量类型
    cout << "i type " << typeid(i).name() << endl; // 输出结果为i(表示int),即类型的名称首字母

    cout << "c++" << endl;

    string s = "success";
    cout << "i type " << typeid(s).name() << endl; // 输出结果为i(表示int),即类型的名称首字母

    result re = get_result(s);
    cout << "&re " << &re
         << "\t" << re.code << ", " << re.msg
         << endl;

    result &rre = get_result(re, s);
    cout << "&rre " << &rre
         << "\t" << rre.code << ", " << rre.msg
         << endl;

}


result get_result(string &input) {
    result r = {200, input};
    return r;
}

result &get_result(result &src, string &input) {
    src.code = 400;
    src.msg = input;

    return src;
}
