//
// Created by Administrator on 2019/6/1.
//  STL（标准模板库）

#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> vec;
    int i;

    cout << "vector size " << vec.size() << endl;

    for (int i = 0; i < 5; i++) {
        vec.push_back(i);
    }

    cout << "extended vector size " << vec.size() << endl;

    for (int i = 0; i < 5; i++) {
        cout << "value of vec[" << i << "] " << vec[i] << endl;
    }

    const vector<int>::iterator &iterator = vec.begin();


    cout << "iterator " << (*(iterator)).end() << endl;

    vector<int >::iterator v = vec.begin();
    while(v != vec.end()){
        cout <<"value of v " << *v << endl;
        v++;
    }


    // 复制 int [] 到 vector
    int casts[10] = {6, 7, 3, 9, 4, 11, 8, 7, 10, 5};
    vector<int> dice(10);
    copy(casts, casts + 10, dice.begin());

    auto value = dice.begin();
    while (dice.end() != value) {
        cout << *value << endl;
        value++;
    }

    return 0;
}