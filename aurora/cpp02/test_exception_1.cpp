//
// Created by Administrator on 2019/9/4.
//

#include <iostream>

using namespace std;

struct MyException : public exception {
    const char *what() const throw() {
        return "C++ exception";
    }
};

int main() {

    try {
        throw MyException();
    } catch (MyException &e) {
        cerr << "myException: " << e.what()<< endl;
    } catch (exception &e) {
        cerr << "exception " << e.what() << endl;
    }


    return 0;
}