//
// Created by Administrator on 2019/6/20.
//

//#include "MoHttp.h"

//int main(void) {
//    srand((unsigned) time(0));
//    MoHttpServer http("8080");
//    return 0;
//}

#include "basic_http.h"

int main(){
    BasicHttp bas;

    bas.Init(1024);
    bas.SendReply("abc", "123");

    return 0;
}