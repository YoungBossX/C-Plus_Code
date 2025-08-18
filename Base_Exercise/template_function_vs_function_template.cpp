/*
 * 主要针对C++泛型编程和ST技术做详细讲解，探讨C++更深层的使用
 *
 * 函数模板
 *  - C++另一种编程思想称为泛型编程 ，主要利用的技术就是模板
 *  - C++提供两种模板机制：函数模板和类模板
 * 
 * 普通函数与函数模板区别：
 *  - 普通函数调用时可以发生自动类型转换（隐式类型转换）
 *  - 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
 *  - 如果利用显示指定类型的方式，可以发生隐式类型转换
 * 
 * 总结：
 *  - 建议使用显示指定类型的方式，调用函数模板，因为可以自己确定通用类型T
 */

#include <iostream>

using namespace std;

int myAdd1(int a, int b)
{
	return a + b;
}

template<typename T>
T myAdd2(T a,T b)
{
	return a + b;
}

void fun() {
    int a = 10;
    double b = 20.0;
    char c = 'c';
    cout << myAdd1(a, c) << endl;
    // cout << myAdd2(a, c) << endl;
    cout << myAdd2<int>(a, c) << endl;
}

int main() {
    fun();

    return 0;
}