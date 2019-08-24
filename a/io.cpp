//
// Created by Major on 2019/2/28 23:45.
//

#include <iostream>
#include <fstream>

using namespace std;

// io流

// 文本文件操作
void method1() {
    cout << "start " << endl;
    char *fname = "d://tmp//dest.txt";
    ofstream fout(fname);

    if (fout.bad()) {
        cout << "error " << endl;
        return;
    }

    fout << "major" << endl;
    fout << "love" << endl;

    fout.close();

    ifstream fin(fname);

    if (fin.bad()) {

        return;
    }

    char ch;
    while (fin.get(ch)) {
        cout << ch;
    }

    cout << endl;

    fin.close();
}

// 二进制文件
void method2() {
    char *src = "e://tmp//src.jpg";
    char *dest = "e://tmp://dest.jag";

    ifstream fin(src, ios::binary);

    ofstream fout(dest, ios::binary);

    if (fin.bad() || fout.bad()) {
        return;
    }

    while (!fin.eof()) {
        char buff[1024] = {0};
        fin.read(buff, 1024);

        fout.write(buff, 1024);
    }

    fin.close();
    fout.close();
}

class Person {
public :
    Person() {}

    Person(char *name, int age) {
        this->name = name;
        this->age = age;
    }

    void print() {
        cout << name << ", " << age << endl;
    }

private:
    char *name;
    int age;
};

// 对象持久化
void method3() {
    Person p1("柳岩", 22);
    Person p2("major", 28);

    ofstream fout("e://tmp/obj.data", ios::binary);
    fout.write((char *) (&p1), sizeof(Person));
    fout.write((char *) (&p2), sizeof(Person));
    fout.close();

    ifstream fin("e://tmp/obj.data", ios::binary);
    Person tmp;
    fin.read((char *) (&tmp), sizeof(Person));
    tmp.print();

    fin.read((char *) (&tmp), sizeof(Person));
    tmp.print();
}

// stl standard template library 标准模板库
#include <string>


void method4(){
    string s1 = "craig david";
    string s2("7 days");
    string s3 = s1 + s2;

    // 转 c 字符串
    const char *str = s1.c_str();
    unsigned long long i = s1.length();

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << str << endl;
}


// 容器

#include <vector>

void method5(){

    // 动态数组（不需要使用动态内存分配）
    vector<int> v1;
    v1.push_back(22);
    v1.push_back(12);
    v1.push_back(5);

    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << endl;
    }

}


int main() {

//    method1();

//    method4();
    method5();

    return 0;
}





