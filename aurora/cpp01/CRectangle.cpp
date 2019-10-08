//
// Created by Administrator on 2019/1/17.
//
#include <iostream>
#include "CRectangle.h"

using namespace std;

void method() {
    char a;
    int b;
    float c;

    cin >> a >> b >> c;
    cout << a << " " << b << " " << c << " " << endl;

}

int main() {
//    method();

    int w, h;
    CRectangle r;
    cout << "addr " << &r << ", len " << sizeof(r)<< endl;



//    cin >> w >> h;

    w = 20;
    h = 50;
    r.init(w, h);
    CRectangle* p = &r;

    cout << "取值 " << p->h << ", " << p->w << endl;
    cout << "取值 " << p->h << ", " << p->w << endl;

    CRectangle& ref = r;

    cout << "取引用 " << ref.h << ", " << ref.w << endl;

    cout << "it's area is " << r.area() << endl;
    cout << "it's perimeter is " << r.perimeter() << endl;
    cout << sizeof(CRectangle) << endl;

    return 0;
}