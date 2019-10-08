//
// Created by Administrator on 2019/2/11.
//

#include <iostream>

using namespace std;

// 轮胎
class CTyre {
private:
    int radius;
    int width;
public:
    CTyre(){}
    CTyre(int r, int w) : radius(r), width(w) {}

};

class CEngine {

};


class CCar {
private:
    int price;
    CTyre tyre;
    CEngine engine;
public:
    CCar();
    CCar(int p, int tr, int tw);

    void string(){
        cout << price << endl;
    }
};
CCar::CCar() {}

CCar::CCar(int p, int tr, int tw) : price(p), tyre(tr, tw) {

}


int main() {
    CCar car(2000, 17, 255);
    car.string();

    CCar c;
    c.string();

    return 0;
}