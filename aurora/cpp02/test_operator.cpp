//
// Created by Administrator on 2019/9/4.
//
#include <iostream>

using namespace std;

class Box {
private:
    int val;

public:
    int operator+(const Box &box);

    void setVal(int val) {
        this->val = val;
    }

};

int Box::operator+(const Box &box) {
    return box.val + val;
}


int main() {

    Box box1;
    box1.setVal(3);
    Box box2;
    box2.setVal(5);

    int b = box1 + box2;
    cout << "b " << b << endl;


    return 0;
}
