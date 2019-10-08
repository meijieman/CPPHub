//
// Created by Administrator on 2019/8/26.
//

#include <string>
#include <iostream>
using namespace std;

class user {
private:
    string name;
public:
    int id;
    user(int _id = -1, string _name = "xiaomei") {
        id = _id;
        name = _name;
    }

    string get_name() {
        return name;
    }

    void set_name(string _name) {
        name = _name;
    }

    int compare(user u) {
        return this->id > u.id;
    }

    void tostring() {
        cout << "id " << id << ", name " << name << endl;
    }
};

int main() {
    user u(100);
    u.tostring();

    user u1 = {21, "xiaoming"};
    u1.tostring();

    user u2 = {};
    u2.tostring();

    user *u_p = new user;
    u_p->set_name("aaaa");
    string name = (*u_p).get_name();
    delete u_p;
    
    int a = 3;
    int b = 5;

    bool rst = a > b;
    int i_rst = a > b;


    return 0;
}
