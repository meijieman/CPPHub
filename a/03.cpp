//
// Created by Major on 2019/1/25 23:12.
//
#include <iostream>

using namespace std;

class Exception {

};

void my() {
    try {
//        throw new Exception;
        throw Exception();
    } catch (Exception &e) {
        cout << "Exception" << endl;
//        delete(e);

    }
}


// �����������׳����쳣����
void mydiv2(int a, int b) throw(char const*, int) {
    if (b == 0) {
        throw "����Ϊ��";
    }
}

void mydiv(int a, int b) {
    if (b == 0) {
        throw "����Ϊ��";
    }
}

// ��׼�쳣


// C++ �쳣����
int main() {
    try {
        int age = 300;

        if (age > 200) {
//            throw age;
            throw "ddd";
//            throw 3.2;
        }
    } catch (int e1) {
        cout << "exception " << e1 << endl;
    } catch (char const *e2) {
        cout << e2 << endl;   //�����쳣��Ȼ��������
    } catch (...) {
        // δ֪�쳣
        cout << "unknow" << endl;
    }

    try {
        mydiv(1, 0);
    } catch (char const *e) {
        cout << e << endl;
    }

    my();
    return 0;
}









