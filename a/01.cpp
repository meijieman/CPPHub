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

/*������̬������
1. �̳�
2. ��������û�ָ��ָ������Ķ���
3. ������д
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
