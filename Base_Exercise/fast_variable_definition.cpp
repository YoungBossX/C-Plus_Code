#include "iostream"

using namespace std;

int main(){
    // 1.定义变量的同时，进行赋值。变量类型 变量名 = 变量值；
    int age = 18;
    string name = "xcc";

    cout << "我的名字叫做：" << name << "，今年" << age << "岁。" << endl;

    // 2.一次性定义多个变量。变量类型 变量名1，变量名2, ... = 变量值, 变量值2, ...;
    int a, b, c;
    a = 10;
    b = 20;
    c = 30;
    cout << "a: " << a << ", b: " << b << ", c: " << c << endl;

    // 3.一次性声明多个变量的同时进行赋值。
    int d = 40, e = 50, f = 60;
    cout << "d: " << d << ", e: " << e << ", f: " << f << endl;

    return 0;
}   