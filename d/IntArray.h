//
// Created by Major on 2018/12/15.
//

#ifndef STUDY_INTARRAY_H
#define STUDY_INTARRAY_H


class IntArray {
public:
    // 构造函数
    explicit IntArray(int sz = DefaultArraySize);
    IntArray(int *array, int array_size);
    IntArray(const IntArray &rhs);

    // 虚拟析构函数
    virtual ~IntArray(){
        delete [] ia;
    }

    // 等于和不等于操作
    bool operator==(const IntArray&) const;
    bool operator!=(const IntArray&) const;

    IntArray& operator=(const IntArray&);

    // 公共方法
    int size() const{ return _size;}

    // 去掉了索引检查功能
    virtual int&operator[](int index){
        return ia[index];
    };
    // virtual 类似 java 的 abstract
    virtual void sort();
    virtual int min() const;
    virtual int max() const;
    virtual int find(int value) const;

protected:
    static const int DefaultArraySize = 12;

    void init(int sz, int *array);

    // 私有变量
    int _size;
    int *ia;
};


#endif //STUDY_INTARRAY_H
