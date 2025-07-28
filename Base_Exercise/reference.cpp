#include "iostream"

using namespace std;

/*
 *   数据类型& 引用名 = 被引用变量；
 *
 *   对引用的操作等同于操作被引用变量。
 */


int main() {
    int a = 10;
    int& b = a;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "a address: " << &a << endl;
    cout << "b address: " << &b << endl;

    a = 20;
    cout << "After changing a:" << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "a address: " << &a << endl;
    cout << "b address: " << &b << endl;

    b = 30;
    cout << "After changing b:" << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "a address: " << &a << endl;
    cout << "b address: " << &b << endl;

    // int num1 =10;
    // int& num2;
    // num2 = num1; // 这里会报错，因为引用必须在声明时初始化

    // int num1 =10;
    // int& num2 = nullptr; // 二者类型完全不兼容
    // num2 = num1; // 指向也不能修改

    double d = 3.14;
    double& e = d;
    cout << "d: " << d << endl;
    cout << "e: " << e << endl;
    cout << "d address: " << &d << endl;
    cout << "e address: " << &e << endl;

    return 0;
}   