//
// Created by Administrator on 2019/9/4.
//

#include <iostream>
#include <string>

using namespace std;

class Line {
public:
    int getLength(void);

    Line(int len);

    Line(const Line &obj);

    ~Line();

private:
    int *ptr;
};

Line::Line(int len) {
    cout << "invoke constructor" << endl;
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj) {
    cout << "invoke copy constructor" << endl;
    ptr = new int;
    *ptr = *obj.ptr;
//    ptr = obj.ptr; // 会报错，因为指针赋值的话，释放时同一个地址调用了两次
    cout << "invoke copy constructor " << &ptr << "  " << &obj.ptr << endl;
}

Line::~Line() {
    cout <<"free mem" << endl;
    delete ptr;
}

int Line::getLength() {
    return *ptr;
}

void display(Line obj){
    cout << "line size: " << obj.getLength() << endl;
}

void display2(Line &obj){
    cout << "line size: 222 " << obj.getLength() << endl;
}


int main() {

    Line line(10);

    display(line);
//    display2(line);

    return 0;
}