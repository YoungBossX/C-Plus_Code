/*
 * 主要针对C++泛型编程和ST技术做详细讲解，探讨C++更深层的使用
 *
 * 函数模板
 *  - C++另一种编程思想称为泛型编程 ，主要利用的技术就是模板
 *  - C++提供两种模板机制：函数模板和类模板
 * 
 * 调用规则如下：
 *  - 如果函数模板和普通函数都可以实现，优先调用普通函数
 *  - 可以通过空模板参数列表来强制调用函数模板
 *  - 函数模板也可以发生重载
 *  - 如果函数模板可以产生更好的匹配，优先调用函数模板
 * 
 * 总结：
 *  - 既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性
 */

#include <iostream>

using namespace std;

void myPrint(int a, int b)
{
	cout << "调用的普通函数" << endl;
}

template<typename T>
void myPrint(T a, T b) 
{ 
	cout << "调用的模板" << endl;
}

template<typename T>
void myPrint(T a, T b, T c) 
{ 
	cout << "调用重载的模板" << endl; 
}

// 注意：如果告诉编译器，普通函数是有的，但只是声明没有实现，或者不在当前文件内实现，就会报错找不到
void func() {
    int a = 10;
    int b = 20;
    int c = 30;

    myPrint(a, b);
    // 可以通过空模板参数列表来强制调用函数模板
    myPrint<>(a, b);

    // 调用重载的函数模板
    myPrint(a, b, c);

    // 如果函数模板可以产生更好的匹配，优先调用函数模板
    char d = 'e';
    char e = 'e';
    myPrint(d, e);
}

int main() {
    func();

    return 0;
}