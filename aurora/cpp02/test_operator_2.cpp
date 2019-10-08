//
// Created by Administrator on 2019/9/4.
//

#include <iostream>

using namespace std;

class Check {
private:
    int i;
public:
    Check() : i(0) {}

    Check operator++() {
        Check temp;
        temp.i = ++i;

        return temp;
    }

    Check operator++(int) {
        Check temp;
        temp.i = i++;

        return temp;
    }

    void display() {
        cout << "i " << i << endl;
    }
};

int main() {

    Check obj, obj1;
    obj.display();
    obj1.display();

    // 调用运算符函数，然后将 obj 的值赋给 obj1
    obj1 = ++obj;
    obj.display();
    obj1.display();

    // 将 obj 赋值给 obj1, 然后再调用运算符函数
    obj1 = obj++;
    obj.display();
    obj1.display();


    return 0;
}

