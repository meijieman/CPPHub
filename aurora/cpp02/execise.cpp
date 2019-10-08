//
// Created by Administrator on 2019/8/28.
// https://blog.csdn.net/u010951938/article/details/41800461


#include <iostream>

using namespace std;

/*
字符串替换：编写一个字符串替换函数，如strSrc为原字符串，strFind是待替换的字符串，strReplace为替换字符串。

举个直观的例子吧，如：“ABCDEFGHIJKLMNOPQRSTUVWXYZ”这个字符串，把其中的“RST”替换为“ggg”这个字符串，结果就变成了：

ABCDEFGHIJKLMNOPQgggUVWXYZ
 */
void replace_str();

/*
 问题描述： 
识别输入字符串中所有的整数，统计整数个数并将这些字符串形式的整数转换为数字形式整数。

要求实现函数： 
void take_num(const char *strIn, int *n, unsigned int *outArray)

【输入】 strIn：   输入的字符串

【输出】 n：       统计识别出来的整数个数

       outArray：识别出来的整数值，其中outArray[0]是输入字符串中从左到右第一个整数，

 outArray[1]是第二个整数，以此类推。数组地址已经分配，可以直接使用

【返回】 无
 */
void take_num(const string strIn, int *n, unsigned int *outArray);


void test_take_num();

/*
 通过键盘输入100以内正整数的加、减运算式，请编写一个程序输出运算结果字符串。
输入字符串的格式为：“操作数1 运算符 操作数2”，“操作数”与“运算符”之间以一个空格隔开。

补充说明：
1. 操作数为正整数，不需要考虑计算结果溢出的情况。
2. 若输入算式格式错误，输出结果为“0”。 

示例 

输入：“4 + 7”  输出：“11”

输入：“4 - 7”  输出：“-3”

输入：“9 ++ 7”  输出：“0” 注：格式错误
 */
int calculate(string str);

int main() {
//    replace_str();

//    test_take_num();


//    string str;
//    if (getline(cin, str)) {
//        cout << calculate(str) << endl;
//    }
    string str = "2 + 3";
    cout << calculate(str) << endl;


    return 0;
}


void replace_str() {
    string strSrc, strFind, strReplace;

    cin >> strSrc >> strFind >> strReplace;
    int i = strSrc.find(strFind);
    int length = strFind.length();
    strSrc.replace(i, length, strReplace);

    cout << strSrc << endl;

}

void take_num(const string strIn, int *n, unsigned int *outArray) {
    int k = 0;
    unsigned int sum = 0;
    for (int i = 0; i < strIn.length(); i++) {
        if (isdigit(strIn[i])) {
            sum = sum * 10 + strIn[i] - '0';
            if (!isdigit(strIn[i + 1])) {
                outArray[k++] = sum;
                (*n)++;
                sum = 0;
            }
        }
    }

}

void test_take_num() {
    unsigned int max_int = 0 - 1;
    printf("The max value of unsigned int on 32 machine: %u\n", max_int);

    string str;
    int n = 0;

    getline(cin, str);

    // unsigned int 范围 0 - 4294967295
    unsigned int *outArray = new unsigned int[str.length()];

    take_num(str, &n, outArray);

    cout << "n = " << n << endl;
    for (int i = 0; i < n; i++) {
        cout << outArray[i] << " ";
    }
    cout << endl;
}

int calculate(string str) {
    int a[3] = {0};

    int sum = 0, k = 0;
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) && str[i] != ' ') {
            sum = sum * 10 + str[i] - '0';
            continue;
        }
        if (str[i] == ' ' || i == str.length() - 1) {
            a[k++] = sum;
            sum = 0;
            continue;
        }

        // 保证只有一个 + 或 -
        if (str.find('+') != str.rfind('+') || str.find('-') != str.rfind('-')) {
            return 0;
        }


        if (str.find('+') != -1) {
            return a[0] + a[1];
        } else if (str.find('-' != -1)) {
            return a[0] - a[1];
        }
    }
}
