//
// Created by Administrator on 2019/2/11.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

/*
 * https://blog.csdn.net/lzs781/article/details/79243306
 */
using namespace std;

typedef struct Config {
    char unrarFile[256];
    char targetFile[256];
    int minLength;
    int maxLength;
    char charSet[256];
    int charSetSize;
} Config;

Config getConfig() {
    Config c;
    ifstream fin("E:\\CLionProjects\\Aurora\\config.txt");
    if (!fin.is_open()) {
        cout << "�����ļ�����ʧ��" << endl;
    }

    while (!fin.eof()) {
        char cbuf[256];
        fin.getline(cbuf, 255);
        string sbuf = cbuf;
        cout << "sbuf" << sbuf << endl;
        if (sbuf == "[��ѹ�����ַ]") {
            fin.getline(c.unrarFile, 255);
        } else if (sbuf == "[Ŀ���ļ���ַ]") {
            fin.getline(c.targetFile, 255);
        } else if (sbuf == "[��С���볤��]") {
            fin.getline(cbuf, 255);
            c.minLength = atoi(cbuf);
        } else if (sbuf == "[������볤��]") {
            fin.getline(cbuf, 255);
            c.maxLength = atoi(cbuf);
        } else if (sbuf == "[�����ַ���]") {
            fin.getline(c.charSet, 255);
            sbuf = c.charSet;
            c.charSetSize = sbuf.length();
        } else {
            cout << "�����ļ���������:" << endl;
            cout << sbuf << endl;
            exit(1);
        }
    }
    fin.close();
    return c;
};

bool test(string targetFile, string password, string unrarFile) {
    string cmd = unrarFile + " t -P" + password + " " + targetFile + " > log.txt";
    if (system(cmd.c_str()) == 0) {
        return true;
    }
    return false;
}

void func(Config *c, string password, int current, int target) {
    if (current == target) {
//        system("cls");
        cout << "��ǰ���Գ��ȣ�" << target << endl;
        cout << "��ǰ�������룺" << password << endl;
        cout << "-----------------" << endl << endl;

        if (test(c->targetFile, password, c->unrarFile)) {
            system("cls");
            cout << "�ƽ�ɹ�" << password << endl;
            system("pause");
            exit(0);
        }

        return;

    }
    for (int i = 0; i < c->charSetSize; i++) {
        string newPassword = password + c->charSet[i];
        func(c, newPassword, current + 1, target);
    }
}

void start(Config c) {
    system("cls");
    cout << "��ʼ�ƽ�.." << endl;
    string password = "";
    for (int i = c.minLength; i <= c.maxLength; i++) {
        func(&c, password, 0, i);
    }
}

int main() {

    cout << "����װ���ļ�������" << endl;
    Config c = getConfig();
    system("cls");
    cout << "�����ļ�װ�سɹ�....." << endl << endl
         << "�����ַ: " << c.unrarFile << endl
         << "Ŀ���ַ: " << c.targetFile << endl
         << "��󳤶�: " << c.maxLength << endl
         << "��С����: " << c.minLength << endl
         << "�� �� ��: " << c.charSet << endl << endl;
    cout << "�Ƿ�ʼ�ƽ�?<Y/N>";
    char i = 'N';
    cin >> i;
    if (i == 'Y' || i == 'y')
        start(c);
    cout << "�ƽ�ʧ��,�볢����չ�ַ������������볤��" << endl;

    system("pause");
}