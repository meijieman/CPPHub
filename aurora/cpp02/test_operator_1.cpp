//
// Created by Administrator on 2019/9/4.
//
#include <iostream>

using namespace std;

class Time {
private:
    int hours; // 0 - 23
    int minutes; // 0 - 59
public:
    Time() {
        hours = 0;
        minutes = 0;
    }

    Time(int h, int m) {
        hours = h;
        minutes = m;
    }

    void displayTime() const{
        cout << "H: " << hours << " M: " << minutes << endl;
    }

    // 重载前缀运算符
    Time operator++() {
        ++minutes;
        if (minutes >= 60) {
            ++hours;
            minutes -= 60;
        }
        return Time(hours, minutes);
    }

    // 重载后缀运算符
    // int 在 括号内是为了向编译器说明这是一个后缀形式，而不是表示整数。
    Time operator++(int) {
        Time t(hours, minutes);
        ++minutes;
        if (minutes >= 60) {
            ++hours;
            minutes -= 60;
        }
//        Time t(hours, minutes);

        return t;
    }
    
    // 重载 Time + int
    Time operator+(int i){
        cout << "h " << hours << ", m " << minutes << endl;
        minutes += i;
        cout << "aft " << minutes << endl;
        if(minutes >=60){
            ++hours;
            minutes -= 60;
        }
        Time t(hours, minutes); //TODO 这个为什么不能像后缀运算符一样卸载上面？

        return t;
    }
};


int main() {

    Time t1(11, 59), t2(11, 59);

    ++t1;
    t1.displayTime();
    ++t1;
    t1.displayTime();

    t2++;
    t2.displayTime();
    t2++;
    t2.displayTime();

    const Time &time = t1 + 2;
    time.displayTime();
    
    return 0;
}
