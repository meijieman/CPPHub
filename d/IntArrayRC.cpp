//
// Created by Major on 2018/12/15.
//
#include <cassert>

#include "IntArrayRC.h"

void swap(IntArray &ia, int i, int j) {
    int tmp = ia[i];
    ia[i] = ia[j];
    ia[j] = tmp;

}

inline int &
IntArrayRC::operator[](int index) {
    check_rang(index);
    return ia[index];
}

inline void
IntArrayRC::check_rang(int index) {
    assert(index >= 0 && index < size());
}

inline IntArrayRC::IntArrayRC(int sz)
        : IntArray(sz) {}

//inline IntArrayRC::IntArrayRC(const int *iar, int sz)
//:IntArray(iar, sz){}


