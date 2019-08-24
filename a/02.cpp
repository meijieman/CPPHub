//
// Created by Major on 2019/1/25 23:12.
//
#include <iostream>

using namespace std;

// 具有纯虚函数的类就是抽象类
class Shape{
public:
    // 纯虚函数
    virtual void sayArea() = 0;
};

class Circle : public Shape{
public:
    Circle (int r){
        this->r = r;
    }

    // 子类要实现父类的纯虚函数，否则还是一个抽象类
    void sayArea(){
        cout << "圆的面积 " << 3.14 * r * r<<  endl;
    }

private:
    int r;
};

int main(){
    Circle c(10);
    c.sayArea();

    return 0;
}


// 接口（只是逻辑上的划分，语法跟抽象类的写法没有区别）
class Brawable{
    // 虚函数和纯虚函数的区别就在于是否有 = 0
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

// 模版函数（函数模版） -> java 的泛型

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










