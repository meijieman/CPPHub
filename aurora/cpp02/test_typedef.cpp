//
// Created by Administrator on 2019/9/3.
//

#include <iostream>
#include <cstring>

using namespace std;

typedef long int *pint32;


typedef struct books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} _books;


int main() {

    pint32 x, y, z;

    long int i = 200;
    x = &i;
    y = &i;


    cout << "i " << i << endl;
    cout << "&x " << x << ", &y " << y << endl;
    cout << "x " << *x << ", y " << *y << endl;

    books b1, b2;
    b1.book_id = 10;
    strcpy(b1.subject, "da");

    cout << b1.book_id << ", " << b1.subject << endl;
    cout << &b2 << endl;

    _books b3;
    strcpy(b3.author, "eeeee");
    cout << b3.author << ", " << b3.subject << endl;

    return 0;
}