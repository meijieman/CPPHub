//
// Created by Administrator on 2019/2/1.
//
#include <iostream>
#include <string>
#include <ctype.h>
/*
ͨ����������100�����������ļӡ�������ʽ�����дһ����������������ַ�����
�����ַ����ĸ�ʽΪ����������1 ����� ������2���������������롰�������֮����һ���ո������
����˵����
1. ������Ϊ������������Ҫ���Ǽ���������������
2. ��������ʽ��ʽ����������Ϊ��0����

 ʾ��
���룺��4 + 7��  �������11��
���룺��4 - 7��  �������-3��
���룺��9 ++ 7��  �������0�� ע����ʽ����
---------------------
���ߣ�С��or��ˮ
��Դ��CSDN
ԭ�ģ�https://blog.csdn.net/u010951938/article/details/41800461
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
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




