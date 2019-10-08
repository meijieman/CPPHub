//
// Created by Administrator on 2019/9/4.
//
/*
 C++ 预处理器
 #include、#define、#if、#else、#line

C++ 中的预定义宏
__LINE__	这会在程序编译时包含当前行号。
__FILE__	这会在程序编译时包含当前文件名。
__DATE__	这会包含一个形式为 month/day/year 的字符串，它表示把源文件转换为目标代码的日期。
__TIME__	这会包含一个形式为 hour:minute:second 的字符串，它表示程序被编译的时间。

 */

#include <iostream>

using namespace std;


#define PI 3.14159

#define DEBUG 1

// 参数宏
#define MIN(a, b) (a < b ? a : b)

// # 运算符会把 replacement-text 令牌转换为用引号引起来的字符串。
#define MKSTR(x) #x

// ## 运算符用于连接两个令牌。
#define CONCAT(x, y) x ## y

#define TRACE  __LINE__ << ": " <<  __FILE__

int main() {

    int i = 100, j = 30;

    cout << "min " << MIN(i, j) << endl;

#if 0
    // 不进行编译的代码

#endif

#if DEBUG
    cerr << "trace: inside main func" << endl;
#endif

    cout << MKSTR(HELLO
                          C++) << endl;

    int xy = 100;

    cout << CONCAT(x, y) << endl;

    cout << __LINE__ << endl;
    cout << __FILE__ << endl;
    cout << __DATE__ << endl;
    cout << __TIME__ << endl;

    cout << TRACE << endl;

    return 0;
}