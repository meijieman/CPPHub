//
// Created by Administrator on 2019/1/17.
//

#ifndef DEMO_CRECTANGLE_H
#define DEMO_CRECTANGLE_H

class CRectangle {
public:
    int w, h;
    void init(int w_, int h_);
    int area();
    int perimeter();
};

void CRectangle::init(int w_, int h_) {
    w = w_;
    h = h_;
}

int CRectangle::area() {
    return w *h;
}

int CRectangle::perimeter() {
    return 2 * (w + h);
}


#endif //DEMO_CRECTANGLE_H
