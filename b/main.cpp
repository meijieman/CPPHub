//
// Created by Major on 2019/3/19 21:55.
//

#include <iostream>
#include <string>

using namespace std;

struct Person{
    int age;
    string name;
} p2{22, "fa"};


class Man{
private:
    char* speak;
    bool tall;

public:
    string content;

    Man(char* _speak, bool _tall){
        speak = _speak;
        tall = _tall;
    }

    void toString(){
        cout << "speak " << speak << ", tall " << tall << ", content " << content << endl;
    }

    ~Man(){
        cout << "析构函数" << endl;
    }
};

void addContent(Man * man, string content);

void method(){

    string s1 = "love who";

    string s2 = s1; // 复制拷贝
    string & s3 = s1; // 创建别名

    s3 = "Mr.right";

    cout << "s1 " << s1 << ", s2 " << s2 << ", s3 " << s3 << endl;

}


int main(){
    struct Person p1 = {22, "major"};

    cout<< p1.age << endl;
    cout<< p1.name << endl;
    cout << p2.name << endl;

    Man m(const_cast<char *>("小华"), false);
    Man m2 = {(char *)"小明", true};

    m.toString();
    m2.toString();

    Man *m_p = &m;
    m_p-> content = "再来点内容";
    m_p->toString();
    cout << "指针" << m_p << endl;

    // new 出来的一定要 del
    Man *pMan = new Man((char*)("new 出来的"), true);
    pMan->toString();
    delete pMan;


    Man *p_m = new Man("xiaobao", true);
    p_m->toString();
    addContent(pMan, "小宝小小宝");
    p_m->toString();
    delete p_m;


    method();

    return 0;
}

void addContent(Man * man, const string content){
    man->content.assign(content);
}