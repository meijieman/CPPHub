//
// Created by Administrator on 2019/2/1.
//
#include <iostream>
#include <string>
#include <ctype.h>
/*
通过键盘输入100以内正整数的加、减运算式，请编写一个程序输出运算结果字符串。
输入字符串的格式为：“操作数1 运算符 操作数2”，“操作数”与“运算符”之间以一个空格隔开。
补充说明：
1. 操作数为正整数，不需要考虑计算结果溢出的情况。
2. 若输入算式格式错误，输出结果为“0”。

 示例
输入：“4 + 7”  输出：“11”
输入：“4 - 7”  输出：“-3”
输入：“9 ++ 7”  输出：“0” 注：格式错误
---------------------
作者：小桥or流水
来源：CSDN
原文：https://blog.csdn.net/u010951938/article/details/41800461
版权声明：本文为博主原创文章，转载请附上博文链接！
 */

using namespace std;

int a[3];

int calculate(string str) {
    int sum = 0, k = 0;
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) && str[i] != ' ') {
            sum = sum * 10 + str[i] - '0';
        }
        if (str[i] == ' ' || i == str.length() - 1) {
            a[k++] = sum;
            sum = 0;
        }
        if (str.find('+') != str.rfind('+') || str.find('-') != str.rfind('-')) {
            return -1;
        }
    }

    if (str.find('+') != -1) {
        return a[0] + a[2];
    } else if (str.find('-') != -1) {
        return a[0] - a[2];
    }

    return -1;
}


int main() {

//    string str;
//    while (getline(cin, str)) {
//        if ("q" == str) {
//            break;
//        }
//        cout << calculate(str) << endl;
//    }

    cout << calculate("188 - 99") << endl;

    return 0;
}




