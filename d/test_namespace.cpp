#include <iostream>

using namespace std;

// �Զ��������ռ�
namespace NSP_A{
    int a = 9;

    struct Teacher{
        char name[20];
        int age;
    };
}
namespace NSP_B {
    int a = 12;
    namespace NSP_C{
        int c = 90;
    }
}

int main() {
    // std ��׼�����ռ�
    std::cout << "Hello, World!" << std::endl;

    printf("ʹ�� c ���������\n");

    cout << NSP_A::a << endl;
    cout << NSP_B::a << endl;
    cout << NSP_B::NSP_C::c << endl;

    // ʹ�������ռ��еĽṹ��
//    struct NSP_A::Teacher t;
//    t.age = 10;

    using namespace NSP_A;
    Teacher t;
    t.age = 20;

    enum color{red, green, blue} a, b ,c;

    a = red;
    b = green;
    c = blue;

    cout << a << b << c << endl;
    
    return 0;
}
