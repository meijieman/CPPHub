//
// Created by Major on 2019/1/25 22:50.
//

#ifndef TMPCPP_JET_H
#define TMPCPP_JET_H

#pragma  once

#include "Plane.h"

class Jet : public Plane {
public:
    virtual void fly();

    virtual void land();
};


#endif //TMPCPP_JET_H
