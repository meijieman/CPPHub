//
// Created by Major on 2019/1/25 23:02.
//

#ifndef TMPCPP_COPTER_H
#define TMPCPP_COPTER_H

#pragma once

#include "Plane.h"

class Copter :public Plane{
public:
    virtual void fly();
    virtual void land();
};


#endif //TMPCPP_COPTER_H
