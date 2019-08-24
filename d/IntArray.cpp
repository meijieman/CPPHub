//
// Created by Major on 2018/12/15.
//

#include <cassert>
#include "IntArray.h"

void
IntArray::
init(int sz, int *array) {
    _size = sz;
    ia = new int[_size];
    for (int ix = 0; ix < _size; ++ix) {
        if (!array)
            ia[ix] = 0;
        else ia[ix] = array[ix];
    }
}

IntArray::IntArray(int sz) {
    init(sz, 0);
}

IntArray::IntArray(int *array, int sz) {
    init(sz, array);
}

IntArray::IntArray(const IntArray &rhs) {
    init(rhs.size(), rhs.ia);
}


//int&
//IntArray::operator[](int index){
//    assert(index >=0 && index < _size);
//    return ia[index];
//}
