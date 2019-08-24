//
// Created by Major on 2018/12/15.
//

#ifndef STUDY_INTARRAYRC_H
#define STUDY_INTARRAYRC_H

#include "IntArray.h"

class IntArrayRC :public IntArray{
public:
    IntArrayRC(int sz = DefaultArraySize);
    IntArrayRC(int *array, int array_size);
    IntArrayRC(const IntArrayRC &rhs);

    virtual int &operator[](int);

private:

    void check_rang(int);

};

#endif //STUDY_INTARRAYRC_H
