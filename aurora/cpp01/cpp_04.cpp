//
// Created by Administrator on 2019/2/1.
//
#include <iostream>
#include <string>
#include <ctype.h>


using namespace std;

/*
���������� 
ʶ�������ַ��������е�������ͳ����������������Щ�ַ�����ʽ������ת��Ϊ������ʽ������

Ҫ��ʵ�ֺ����� 
void take_num(const char *strIn, int *n, unsigned int *outArray)
�����롿 strIn��   ������ַ���
������� n��       ͳ��ʶ���������������
       outArray��ʶ�����������ֵ������outArray[0]�������ַ����д����ҵ�һ��������
 outArray[1]�ǵڶ����������Դ����ơ������ַ�Ѿ����䣬����ֱ��ʹ��

�����ء� ��

ע��

I��     �������ַ����г��ֵ�������(+, -)��������ת�����Ϊ�Ǹ�����������0����������
II��    ������ת��������������Χ����������������п��ܳ��ֵ�����������ᳬ��unsigned int�ɴ���ķ�Χ
III��   ��Ҫ���� '0' ��ʼ�������ַ������������ "00035" ��Ӧת��Ϊ����35��
        "000" Ӧת��Ϊ����0��"00.0035" Ӧת��Ϊ����0��35������С���㣺mmm.nnn����������mmm��nnn��ʶ��
IV��   �����ַ������ᳬ��100 Bytes���벻�ÿ��ǳ����ַ����������
ʾ��
���룺strIn = "ab00cd+123fght456-25  3.005fgh"
�����n = 6
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
    getline(cin, str); // ��Ҫ������ո�Ĵ����� getline(cin,str); �滻 cin>>str;
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


// �ֲ����������ȸ�ֵ��ʹ�á�
void test_init(){
    int count ;
    cout << "test_init " << count << endl;

    int a ;
    cout << "������ " << a << endl;
}


int main() {

//    test_take_num();

//    test_take_num_1();

    test_init();

    int i;
    cout << "main " << i << endl;

    return 0;
}




