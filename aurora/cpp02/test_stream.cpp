//
// Created by Administrator on 2019/9/4.
//

#include <iostream>
#include <fstream>

using namespace std;


int main() {

    char data[100];

    ofstream outfile;
    // ios::app	追加模式。所有写入都追加到文件末尾。
    // ios::ate	文件打开后定位到文件末尾。
    // ios::in	打开文件用于读取。
    // ios::out	打开文件用于写入。默认
    // ios::trunc	如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0。
    outfile.open("afile.dat"); // 默认文件路径 E:\CLionProjects\Aurora\bin\cpp\afile.dat
    if (!outfile.is_open()) {
        cout << "file cannot open" << endl;
        return -1;
    }

    cout << "writing to the file" << endl;
    cout << "enter your name: ";

    cin.getline(data, 100);
    outfile << data << endl;

    cout << "enter your age: ";
    cin >> data;
    cin.ignore();

    outfile << data << endl;

    outfile.close();

    ifstream infile;
    infile.open("afile.dat");

    cout << "reading form the file" << endl;
    infile >> data;

    cout << data << endl;

    infile >> data;
    cout << data << endl;

    infile.close();


    return 0;
}