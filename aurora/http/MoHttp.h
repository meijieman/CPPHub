//
// Created by Administrator on 2019/6/20.
//

#pragma once
#define _MOHTTP_H
#ifdef _MOHTTP_H

#include "mongoose.h"
#include <iostream>

using namespace std;
const int CHAR_HTTP_VAR_MAX = 800000;
const int CHAR_HTTP_COOKIE_MAX = 400;

class MoHttp {
private:
    struct http_message *hm = NULL;

public:
    MoHttp(struct http_message *);

    ~MoHttp();

    int getGetVar(const char *, char *) const;    //获取变量
    void getGetVar(const char *, string &) const;    //获取变量
    int getPostVar(const char *, char *) const;

    //获取变量
    bool send(mg_connection *nc, int status_code, const char *data);

    void getPostVar(const char *, string &) const;    //获取变量
    int getCookie(const char *, char *) const;    //获取Cookie
    void getCookie(const char *, string &) const;    //获取Cookie
    int Model() const;    //判断当前模式 POST/GET    1为 GET 否则为0
};

class MoHttpServer {
public:
    MoHttpServer(char *);

    ~MoHttpServer();
};

#endif
