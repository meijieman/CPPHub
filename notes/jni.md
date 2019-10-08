
JNI (Java Native Interface)

java 调用 C/C++，C/C++ 调用 java 的一套 API


## jni 开发流程
1. 在 java 编写 native 方法
2. javah 命令，生成 .h 头文件
    javah -classpath . com.company.JniTest
    注意在添加 classpath 参数，否则需要在环境变量配置 classpath
3. 复制 .h 头文件到 C 工程
4. 复制 jni.h 和 jni_md.h 到 C 工程
5. 实现 .h 头文件中声明的函数
6. 生成 dll 动态链接库文件(clion 生成的动态库文件名会在前面加上 lib，需要手动删除)
7. 在 java 中调用动态库，配置动态库环境变量（可以在系统path中添加dll所在目录，或在 ide 中配置）
```java
    // 注意不要把后缀 .dll 写进来了
    static{
        // 打印环境变量
        String property = System.getProperty("java.library.path");
        System.out.println(property);    
        System.loadLibrary("jni");
//        System.load("E:\\05_java\\demo\\lib\\jni.dll");      
    }
```


## 动态库，静态库区别
.a 静态库
.dll 动态库 共享代码


## JNIEnv
JNIEnv 是结构体指针，代表 java 运行环境， 调用 java 中的代码

```
JNIEnv *env
```
env 在 C 中是结构体的二级指针
JNIEnv 在 C++ 中是一个结构体的别名 ，env 在 C++ 中是一个结构体的指针

C 程序函数执行过程中需要使用 JNIEnv，而 C++ 有 this 关键字，能拿到当前函数。


每个 native 函数都至少有两个参数（JNIEnv*, jclass 或 jobject)
当 native 方法为静态方法时，
jclass 代表 native 方法所属类的 class 对象
当 native 方法为非静态方法时，
jobject 代表 native 方法所属的对象

## jni 数据类型
### JNI 基本数据类型
java 类型 -> JNI 类型 -> C 类型
boolean jboolean    unsigned char  
byte    jbyte       signed char  
char    jchar       unsigned short   
short   jshort      short  
int     jint        int  
long    jlong       long long  
float   jfloat      float  
double  jdouble     double  
void    void

### 引用类型
String  jstring
Object  jobject
byte[]  jByteArray
Object[](String[]) jobjectArray

### 相关命令
生成头文件
```javah -classpath . -jni com.company.JniTest```
查看方法签名（在生成的 JniTest.class 的包目录下执行如下命令）
```javap -classpath . -s -p com.company.JniTest```

```javap -s -p java.util.Date```

## C/C++ 访问 java 成员__int64



## 参考
* [使用 IntelliJ IDEA 和 IntelliJ Clion 进行 JNI 开发](https://blog.csdn.net/liangjiu2009/article/details/77063704)
* [Clion c++调用c动态链接库](https://blog.csdn.net/v2sking/article/details/84495941)
* [CMakeLists实战解读--YouCompleteMe](https://www.cnblogs.com/rickyk/p/3877238.html)
 
 https://blog.csdn.net/wsxzhbzl/article/details/82727034















