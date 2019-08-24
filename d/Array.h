//
// Created by Major on 2018/12/15 11:33.
//

#ifndef STUDY_ARRAY_H
#define STUDY_ARRAY_H

namespace Cplusplus_Primer_3E {

    template<class elemType>
    class Array {

    public:
        explicit Array(int size = DefaultArraySize);

        Array(elemType *array, int array_size);

        Array(const Array &rhs);

        virtual ~Array() {
            delete[] ia;
        }

        bool operator==(const Array &) const;

        bool operator!=(const Array &) const;

        Array &operator=(const Array &);

        int size() const {
            return _size;
        }

        virtual elemType &operator[](int index) {
            return ia[index];
        }

        virtual void sort();

        virtual elemType min() const;

        virtual elemType max() const;

        virtual int find(const elemType &value) const;

    protected:
        static const int DefaultArraySize = 12;
        int _size;
        elemType *ia;


    };
}

#endif //STUDY_ARRAY_H
