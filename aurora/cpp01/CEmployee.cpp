//
// Created by Administrator on 2019/1/17.
//

#include <iostream>
#include <cstring>

using namespace std;

class CEmployee{
private:
    char szName[30];
public:
    int salay;
    char* remark;

    void init(char *name);
    void setName(char *name);
    void getName(char *name);
    void averageSalary(CEmployee e1, CEmployee e2);
    void print();
};

void CEmployee::init(char *name) {
    strcpy(szName, name);
}
void CEmployee::setName(char *name) {
    strcpy(szName, name);
}

void CEmployee::getName(char *name) {
    strcpy(name, szName);
}

void CEmployee::averageSalary(CEmployee e1, CEmployee e2) {
    salay = (e1.salay + e2.salay) / 2;
}

void CEmployee::print(){
    cout << salay << ", " << szName<< " " << remark << endl;
}


int main(){
    CEmployee e;
//    strcpy(e.szName, "tom123456789");
    e.setName("tom");
    e.salay = 5000;

    e.remark = "qqqq";

    e.print();

    CEmployee ee;
    ee.init("eafa");


    return 0;
}
