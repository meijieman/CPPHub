//
// Created by Administrator on 2019/6/20.
//

#include "MoHttp.h"

MoHttp::MoHttp(struct http_message *hm = NULL) {
    this->hm = hm;
}

int MoHttp::getGetVar(const char *name, char *var) const {
    memset(var, '\0', sizeof(var));
    if (hm == NULL || name == NULL || hm->query_string.p == NULL)return -1;
    return mg_get_http_var(&hm->query_string, name, var, sizeof(var));        //获取变量
}

void MoHttp::getGetVar(const char *name, string &str) const {
    str = "";
    char var[CHAR_HTTP_VAR_MAX];
    var[0] = '\0';
    if (hm == NULL || name == NULL || hm->query_string.p == NULL)return;
    mg_get_http_var(&hm->query_string, name, var, sizeof(var));        //获取变量
    if (var[0] == '\0') {
        return;
    }
    str = var;    //如果数据正确
}

int MoHttp::getPostVar(const char *name, char *varA) const {
    static char var[CHAR_HTTP_VAR_MAX];
    var[0] = '\0';
    if (hm == NULL || name == NULL/* || hm->query_string.p == NULL*/)return 0;
    INT A = mg_get_http_var(&hm->body, name, var, sizeof(var));        //获取变量
    if (var[0] == '\0') {
        return 0;
    }
    memcpy(varA, var, A);
    varA[A] = '\0';
    return A;
//	delete[] var;
}

bool MoHttp::send(struct mg_connection *nc, int status_code, const char *data) {
    mg_http_send_error(nc, 404, data);
    return true;
}

void MoHttp::getPostVar(const char *name, string &str) const {
    str = "";
    char var[CHAR_HTTP_VAR_MAX];
    var[0] = '\0';
    if (hm == NULL || name == NULL || hm->query_string.p == NULL)return;
    mg_get_http_var(&hm->body, name, var, sizeof(var));        //获取变量
    if (var[0] == '\0') {
        return;
    }
    printf("%s\n", var);
    str = var;    //如果数据正确
}

int MoHttp::Model() const {

    if (hm == NULL || hm->method.p == NULL)return -1;    //数据错误
    if (mg_vcmp(&hm->method, "POST") != 0)return 1;
    return 0;

}

int MoHttp::getCookie(const char *name, char *var) const {
    memset(var, '\0', sizeof(var));
    //mg_printf(nc, "Set-Cookie: %s=%s; path=/\r\n", "wwe", "123456789");    发送Cookie
    if (hm == NULL) return -999;
    struct mg_str *cookie_header = mg_get_http_header(hm, "cookie");    //获取Cookie 整条
    if (cookie_header == NULL) return -999; //<0
    return mg_http_parse_header(cookie_header, name, var, sizeof(var));
}

void MoHttp::getCookie(const char *name, string &str) const {
    str = "";
    char var[CHAR_HTTP_COOKIE_MAX];    //Cookie 最大更长
    var[0] = '\0';
    if (hm == NULL || name == NULL || hm->query_string.p == NULL)return;
    struct mg_str *cookie_header = mg_get_http_header(hm, "cookie");    //获取Cookie 整条
    if (cookie_header == NULL) return;
    mg_http_parse_header(cookie_header, name, var, sizeof(var));
    if (var[0] == '\0') {
        return;
    }
    str = var;    //如果数据正确
}

MoHttp::~MoHttp() {

}