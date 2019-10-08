//
// Created by Administrator on 2019/2/1.
//
#include <iostream>

using namespace std;


/*
字符串替换：编写一个字符串替换函数，如strSrc为原字符串，strFind是待替换的字符串，strReplace为替换字符串。
举个直观的例子吧，如：“ABCDEFGHIJKLMNOPQRSTUVWXYZ”这个字符串，把其中的“RST”替换为“ggg”这个字符串，结果就变成了：ABCDEFGHIJKLMNOPQgggUVWXYZ
 */

int main() {

    string strSrc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string strFind = "RST";
    string strReplace = "ggg";

    int i = strSrc.find(strFind);
    int length = strFind.length();
    strSrc.replace(i, length, strReplace);

    cout << strSrc << endl;

    return 0;
}




