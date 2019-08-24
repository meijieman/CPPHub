//
// Created by Major on 2019/1/12 10:25.
//

#include <iostream>
using namespace std;

#define PI 3.14
class MyCircle {
private:
    double r;
    double s;
public:
    void setR(double r) {
        this->r = r;
    }

    double getS(){
        return PI * r *r;
    }
};

int main(){

    MyCircle c1;
    c1.setR(4);
    cout << "Ô²µÄÃæ»ý " << c1.getS() << endl;

    return 0;
}
