//
// Created by Administrator on 2019/2/1.
//
#include <iostream>

using namespace std;


/*
�ַ����滻����дһ���ַ����滻��������strSrcΪԭ�ַ�����strFind�Ǵ��滻���ַ�����strReplaceΪ�滻�ַ�����
�ٸ�ֱ�۵����Ӱɣ��磺��ABCDEFGHIJKLMNOPQRSTUVWXYZ������ַ����������еġ�RST���滻Ϊ��ggg������ַ���������ͱ���ˣ�ABCDEFGHIJKLMNOPQgggUVWXYZ
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




