#include "iostream"

using namespace std;

/*
 * 作用：函数名可以相同，提高复用性
 *
 * 函数重载满足条件：
 * - 同一个作用域下
 * - 函数名称相同
 * - 函数参数类型不同 或者 个数不同 或者 顺序不同
 *
 * 注意：函数的返回值不可以作为函数重载的条件
 */


void func() {
    cout << "this is a func without parameter!" << endl;
}

void func(int a) {
    cout << "this is a func with int parameter." << endl;
}

void func(double a) {
    cout << "this is a func with double parameter!" << endl;
}

void func(int a, double b) {
    cout << "this is a func with int and double parameters!" << endl;
}

void func(double a, int b) {
    cout << "this is a func with double and int parameters!" << endl;
}

// int func(double a) {
//     cout << "this is a func with double parameter, but return int!" << endl;
// }

void func(int a, double b, int c) {
    cout << "this is a func with int, double and int parameters!" << endl;
}

// 函数重载的注意事项
// 1.引用作为重载的条件

void func_1(int& a) { // int& a = 10 不合法，因为10是常量，不能被修改
    cout << "func调用！" << endl;
}

void func_1(const int& a) { // 注意：这里的const int& a和int& a是不同的参数类型，加coonst只读不能写。加了const编译器会给代码做优化相当于会创建一个临时变量，让a指向这个临时变量
    cout << "func调用！！" << endl;
}

// 2.函数重载碰到默认参数
void func_2(int a) {
    cout << "func_2调用！" << endl;
}

// void func_2(int a, int b) {
//     cout << "func_2调用！！" << endl;
// }

void func_2(int a, int b = 10) { // 当函数重载碰到默认参数，出现二义性，报错，尽量避免这种情况
    cout << "func_2调用！！" << endl;
}

int main() {
    func();
    func(10);
    func(10.0);
    func(10, 10.0);
    func(10.0, 10);
    func(10, 10.0, 10);

    int a = 10;
    func_1(a);
    func_1(10); // 这里会调用const int& a的重载版本，因为10是常量，不能被修改

    // func_2(10);
    func_2(10, 20);

    return 0;
}