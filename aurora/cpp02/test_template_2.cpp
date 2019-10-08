//
// Created by Administrator on 2019/9/4.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

// 类模板

template<class T>
class Stack {
private:
    vector<T> elems;
public:
    void push(T const &);

    void pop();

    T top() const;

    bool empty() const {
        return elems.empty();
    }
};

template<class T>
void Stack<T>::push(const T &elem) {
    elems.push_back(elem);
}

template<class T>
void Stack<T>::pop() {
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop(): empty stack()");
    }
    elems.pop_back();
}

template<class T>
T Stack<T>::top() const {
    if (elems.empty()) {
        throw out_of_range("Stack<>::top(): empty stack()");
    }
    return elems.back();
}


int main() {

    try {
        Stack<int> intStack;
        intStack.push(7);
        cout << intStack.top() << endl;

        Stack<string> stringStack;
        stringStack.push("hello");
        cout << stringStack.top() << endl;
        stringStack.pop();
        stringStack.pop();

    } catch (exception const &ex) {
        cerr << "exception " << ex.what() << endl;
        return -1;
    }


    return 0;
}





