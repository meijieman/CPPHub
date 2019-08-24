//
// Created by Major on 2019/3/20 21:24.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){

    const int N = 6;
    string s1[N] = {"hell", "cc", "acc", "bb", "dd", "kk"};
    string s2[N] = {"hell", "ucc", "yacc", "nbb", "mdd", "ckk"};
    set<string> A(s1, s1 + N);
    set<string> B(s2, s2 + N);
    ostream_iterator<string, char> out(cout, " ");

    cout << "Set A:";
    copy(A.begin(), A.end(), out);
    cout << endl;

    cout << "Set B:";
    copy(B.begin(), B.end(), out);
    cout << endl;

    cout << "Union of A and B: ";
    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    return 0;

}