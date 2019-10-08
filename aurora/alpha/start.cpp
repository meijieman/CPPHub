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
        cout << "配置文件加载失败" << endl;
    }

    while (!fin.eof()) {
        char cbuf[256];
        fin.getline(cbuf, 255);
        string sbuf = cbuf;
        cout << "sbuf" << sbuf << endl;
        if (sbuf == "[解压引擎地址]") {
            fin.getline(c.unrarFile, 255);
        } else if (sbuf == "[目标文件地址]") {
            fin.getline(c.targetFile, 255);
        } else if (sbuf == "[最小密码长度]") {
            fin.getline(cbuf, 255);
            c.minLength = atoi(cbuf);
        } else if (sbuf == "[最大密码长度]") {
            fin.getline(cbuf, 255);
            c.maxLength = atoi(cbuf);
        } else if (sbuf == "[密码字符集]") {
            fin.getline(c.charSet, 255);
            sbuf = c.charSet;
            c.charSetSize = sbuf.length();
        } else {
            cout << "配置文件内容有误:" << endl;
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
        cout << "当前尝试长度：" << target << endl;
        cout << "当前尝试密码：" << password << endl;
        cout << "-----------------" << endl << endl;

        if (test(c->targetFile, password, c->unrarFile)) {
            system("cls");
            cout << "破解成功" << password << endl;
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
    cout << "开始破解.." << endl;
    string password = "";
    for (int i = c.minLength; i <= c.maxLength; i++) {
        func(&c, password, 0, i);
    }
}

int main() {

    cout << "正在装配文件。。。" << endl;
    Config c = getConfig();
    system("cls");
    cout << "配置文件装载成功....." << endl << endl
         << "引擎地址: " << c.unrarFile << endl
         << "目标地址: " << c.targetFile << endl
         << "最大长度: " << c.maxLength << endl
         << "最小长度: " << c.minLength << endl
         << "字 符 集: " << c.charSet << endl << endl;
    cout << "是否开始破解?<Y/N>";
    char i = 'N';
    cin >> i;
    if (i == 'Y' || i == 'y')
        start(c);
    cout << "破解失败,请尝试扩展字符集或增加密码长度" << endl;

    system("pause");
}