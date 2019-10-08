//
// Created by Administrator on 2019/2/11.
//

#include <iostream>

using namespace std;

class CSample {
public:
    CSample() {
        cout << "Constructor 1 Called" << endl;
    }

    CSample(int n) {
        cout << "Constructor 2 Called" << endl;
    }
};

int main() {
    CSample array[2];
    cout << "step 1 " << endl;
    CSample array2[2] = {4, 5};
    cout << "step 2" << endl;
    CSample array3[2] = {3};
    cout << "step 3" << endl;
    CSample *array4 = new CSample[2];
    delete[] array4;
    cout << "step 4" << endl;

    CSample array5[3] = {2, CSample(4)};
    cout << "step 5" << endl;

    CSample * array6 = {new CSample(3)};

    CSample c(888);
    CSample array7(c);

    CSample *pSample = new CSample(3);


    return 0;
}