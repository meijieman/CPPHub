//
// Created by Major on 2019/1/25 22:54.
//

#include "Plane.h"
#include "Jet.h"
#include "Copter.h"

void bizPlay(Plane &p) {
    p.fly();
    p.land();
}

/*发生多态的条件
1. 继承
2. 父类的引用或指针指向子类的对象
3. 函数重写
*/
int main(){
    Plane p1;
    bizPlay(p1);

    Jet p2;
    bizPlay(p2);

    Copter p3;
    bizPlay(p3);

    return 0;
}
