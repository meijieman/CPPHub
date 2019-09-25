#include <iostream>

using namespace std;

class RunClass {
public :
    void BalanceArray(int array1[], int array2[], int n1, int n2);

private :
    int Sum(int array[], int n);
};

void RunClass::BalanceArray(int array1[], int array2[], int n1, int n2) {

    if (n1 != n2)
        return;
    int *array = new int[n1];
    if (Sum(array1, n1) < Sum(array2, n2)) {

        array = array1;
        array1 = array2;
        array2 = array;
    }
    bool ifCycle = true;
    int length = n1;
    while (ifCycle) {
        ifCycle = false;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                int itemValue = array1[i] - array2[j];
                int sumValue = Sum(array1, n1) - Sum(array2, n2);
                if (itemValue < sumValue && itemValue > 0) {
                    ifCycle = true;
                    int item = array1[i];
                    array1[i] = array2[j];
                    array2[j] = item;
                }
            }
        }
    }
}

int RunClass::Sum(int array[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    return sum;
}

int main() {
    int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 90, 0, 0, 100};
    int array2[] = {-1, -2, -100, -3, 99, -222, -2, -3, -5, -88, 11, 12, 13};


//   int array1[] = { 1, 2, 3 };  
//   int array2[] = { -1, -2, -100 };

    RunClass a;
    a.BalanceArray(array1, array2, 13, 13);

    for (int i = 0; i < 13; i++)
        cout << array1[i] << "  ";
    cout << endl;

    for (int i = 0; i < 13; i++)
        cout << array2[i] << "  ";
    cout << endl;

    return 0;

}
