//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;

// �̳����̬

class Human {
public:
    Human(char *name, int age) {
        this->name = name;
        this->age = age;
    }

    void say() {
        cout << "˵��" << endl;
    }

    int count;

protected:
    char *name;
    int age;

};

// �̳�
class Man : public Human {
public:
    Man(char *brother, char *s_name, char s_age)
    : Human(s_name, s_age) {
        this->brother = brother;
    }

    void chasing() {
        cout << "pao" << endl;
    }

    // ���Ƕ�̬���Ǹ���
    void say() {
        cout << "���� ˵��" << endl;
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

    // �������͵����û�ָ��
    Human *h_p = &m1;
    h_p->say();

    Human &h1 = m1;
    h1.say();

    Human h2 = m1;

    // ���ø���� say ����
    m1.Human::say();
    m1.Human::count = 1;


    return 0;
}

