//
// Created by Major on 2019/1/12 10:34.
//

#include <iostream>

using namespace std;

// ���캯�������Գ�ʼ���б�
class Teacher{
private:
    char* name;
public:
    static int total;

    Teacher(char* name){
        this->name = name;
        cout << "�вι��캯��" << endl;
    }
    ~Teacher(){
        cout << "��������" << endl;

    }

    char* getName(){
        return this->name;
    }
    void setName(char* name){
        this->name = name;
    }

    // ��̬����
    static void count(){
        total++;
    }
};

class Student{
private:
    int id;
    Teacher t1;
    Teacher t2;

public:
    Student(int id, char *t1_n, char *t2_n)
            : t1(t1_n),
              t2(t2_n) {
        this->id = id;
    }

    void myprint(){
        cout << id << ", " << t1.getName() << ", " << t2.getName() << endl;
    }

    ~Student(){
        cout << "Student ��������" << endl;

    }
};


// C++ д���� C д���������� C++ �Ļ���ù��캯��������������C ��д������
void func(){
    // C++
    Teacher *t1 = new Teacher("jack");
    cout << t1->getName() << endl;
    delete  t1; // �ֶ��ͷ�

    // C
    Teacher* t2 = (Teacher* ) malloc(sizeof(Teacher));
    t2->setName("jack");
    free(t2);

}

// static
void func2(){
    Teacher::total++;
    cout << Teacher::total << endl;

    Teacher::count();

    Teacher t1("yuehan");
    t1.count();
}


// ��̬���Գ�ʼ����ֵ
int Teacher::total = 9;

int main() {
    Student s1(10, "miss bo", "ms liu");
//    Student s2(20, "jason", "jason");

    s1.myprint();
//    s2.myprint();


    func();


    // C
    int* p1 = (int*) malloc(sizeof(int)*10);
    p1[0] = 0;
    free(p1);

    // C++
    int *p2 = new int[10];
    p2[0] = 2;
    // �ͷ�����
    delete[] p2;

    func2();

    return 0;
}

