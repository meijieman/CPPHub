#include <iostream>

using namespace std;

// 自定义命名空间
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
    // std 标准命名空间
    std::cout << "Hello, World!" << std::endl;

    printf("使用 c 的输出函数\n");

    cout << NSP_A::a << endl;
    cout << NSP_B::a << endl;
    cout << NSP_B::NSP_C::c << endl;

    // 使用命名空间中的结构体
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
