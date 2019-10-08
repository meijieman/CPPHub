//
// Created by Administrator on 2019/2/1.
//
#include <iostream>
#include <string>
#include <ctype.h>


using namespace std;

/*
问题描述： 
识别输入字符串中所有的整数，统计整数个数并将这些字符串形式的整数转换为数字形式整数。

要求实现函数： 
void take_num(const char *strIn, int *n, unsigned int *outArray)
【输入】 strIn：   输入的字符串
【输出】 n：       统计识别出来的整数个数
       outArray：识别出来的整数值，其中outArray[0]是输入字符串中从左到右第一个整数，
 outArray[1]是第二个整数，以此类推。数组地址已经分配，可以直接使用

【返回】 无

注：

I、     不考虑字符串中出现的正负号(+, -)，即所有转换结果为非负整数（包括0和正整数）
II、    不考虑转换后整数超出范围情况，即测试用例中可能出现的最大整数不会超过unsigned int可处理的范围
III、   需要考虑 '0' 开始的数字字符串情况，比如 "00035" ，应转换为整数35；
        "000" 应转换为整数0；"00.0035" 应转换为整数0和35（忽略小数点：mmm.nnn当成两个数mmm和nnn来识别）
IV、   输入字符串不会超过100 Bytes，请不用考虑超长字符串的情况。
示例
输入：strIn = "ab00cd+123fght456-25  3.005fgh"
输出：n = 6
outArray = {0, 123, 456, 25, 3, 5}
 */
int k = 0, n = 0;

void take_num(const string strIn, int *outArray) {
    int sum = 0;
    for (int i = 0; i < strIn.length(); i++) {
        if (isdigit(strIn[i])) {
            sum = sum * 10 + strIn[i] - '0';
            if (!isdigit(strIn[i + 1])) {
                outArray[k++] = sum;
                n++;
                sum = 0;
            }
        }
    }
}

void test_take_num() {
    string str;
    getline(cin, str); // 若要读入带空格的串，用 getline(cin,str); 替换 cin>>str;
    int *outArray = new int[str.length()];
    take_num(str, outArray);

    cout << n << endl;
    for (int i = 0; i < k; i++) {
        cout << outArray[i] << " ";
    }
    cout << endl;
}

void take_num_1(string strIn, int *count, int *outArray) {
    int sum = 0;
    int index = 0;

    for (int i = 0; i < strIn.length(); i++) {
        if (isdigit(strIn[i])) {
            sum = sum * 10 + strIn[i] - '0';
            if (!isdigit(strIn[i + 1])) {
                outArray[index++] = sum;

                (*count)++;
                sum = 0;
            }
        }
    }
}

void test_take_num_1() {
    string str = "ab00cd+123fght456-25  3.005fgh";

    int *outArray = new int[str.length()];

    int count ;
    cout << "test_take_num_1 " << count << endl;

    take_num_1(str, &count, outArray);
    cout << count << endl;

    for (int i = 0; i < count; i++) {
        cout << outArray[i] << " ";
    }
    cout << endl;
}


// 局部变量必须先赋值再使用。
void test_init(){
    int count ;
    cout << "test_init " << count << endl;

    int a ;
    cout << "见鬼了 " << a << endl;
}


int main() {

//    test_take_num();

//    test_take_num_1();

    test_init();

    int i;
    cout << "main " << i << endl;

    return 0;
}




