//
// Created by Major on 2019/1/25 23:12.
//
#include <iostream>

using namespace std;

// ���д��麯��������ǳ�����
class Shape{
public:
    // ���麯��
    virtual void sayArea() = 0;
};

class Circle : public Shape{
public:
    Circle (int r){
        this->r = r;
    }

    // ����Ҫʵ�ָ���Ĵ��麯����������һ��������
    void sayArea(){
        cout << "Բ����� " << 3.14 * r * r<<  endl;
    }

private:
    int r;
};

int main(){
    Circle c(10);
    c.sayArea();

    return 0;
}


// �ӿڣ�ֻ���߼��ϵĻ��֣��﷨���������д��û������
class Brawable{
    // �麯���ʹ��麯��������������Ƿ��� = 0
    virtual void draw() = 0;
};

/*void myswap(int &a, int &b){
    int tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
}

void myswap(char &a, char &b){
    char tmp = 0;
    tmp =a;
    a = b;
    b = tmp;
}*/

// ģ�溯��������ģ�棩 -> java �ķ���

template <typename T>
void myswap(T &a, T &b){
    T tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
}

template <typename T, typename Y>
void myswap2(T &a, T &b, Y y){

}



void method(){
    int a = 10;
    int b = 20;
    myswap(a, b);

    char x = 'v';
    char y = 'w';
    myswap<char>(x, y);
}










