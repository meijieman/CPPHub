//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;

// 继承与多态

class Human {
public:
    Human(char *name, int age) {
        this->name = name;
        this->age = age;
    }

    void say() {
        cout << "说话" << endl;
    }

    int count;

protected:
    char *name;
    int age;

};

// 继承
class Man : public Human {
public:
    Man(char *brother, char *s_name, char s_age)
    : Human(s_name, s_age) {
        this->brother = brother;
    }

    void chasing() {
        cout << "pao" << endl;
    }

    // 不是多态，是覆盖
    void say() {
        cout << "男人 说话" << endl;
    }

private:
    char *brother;

};

void work(Human &h) {
    h.say();
}

int main() {
    Man m1("danny", "jack", 18);
    m1.say();
    m1.chasing();

    // 父类类型的引用或指针
    Human *h_p = &m1;
    h_p->say();

    Human &h1 = m1;
    h1.say();

    Human h2 = m1;

    // 调用父类的 say 方法
    m1.Human::say();
    m1.Human::count = 1;


    return 0;
}

