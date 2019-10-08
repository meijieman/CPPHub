//
// Created by Administrator on 2019/9/4.
//
#include <iostream>


using namespace std;

class Shape {
public:
    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }

    virtual int getArea() { return 0; };


protected:
    int width;
    int height;
};


class PaintCost {
public:
    int perCost = 10;

    int getCost(Shape &shape) {
        return shape.getArea() * perCost;
    }

    void setPerCost(int perCost) {
        this->perCost = perCost;
    }
};

class Rectangle : public Shape, public PaintCost {
public:
    int getArea() {
        return (width * height);
    }

};


void print(PaintCost &pc, Shape &s) {
    cout << "print " << pc.getCost(s) << endl;
}

int main() {

    Shape *rect = new Rectangle;
    rect->setWidth(5);
    rect->setHeight(7);

    int area = rect->getArea();
    cout << "area " << area << endl;
    
    
    Rectangle r;
    r.setWidth(2);
    r.setHeight(3);

    cout << "a " << r.getArea() << endl;
    cout << "cost " << r.getCost(r) << endl;

    print(r, r);


    return 0;
}

