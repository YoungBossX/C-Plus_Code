/*
 * 主要针对C++泛型编程和ST技术做详细讲解，探讨C++更深层的使用
 *
 * 函数模板
 *  - C++另一种编程思想称为泛型编程 ，主要利用的技术就是模板
 *  - C++提供两种模板机制：函数模板和类模板
 * 
 * 注意事项：
 *  - 自动类型推导，必须推导出一致的数据类型T，才可以使用
 *  - 模板必须要确定出T的数据类型，才可以使用
 * 
 * 总结：
 *  - 使用模板时必须确定出通用数据类型T，并且能够推导出一致的类型
 */

#include <iostream>

using namespace std;

template<class T> // typename可以替换成class
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// 1.自动类型推导，必须推导出一致的数据类型T,才可以使用
void func1() {
    int a = 10, b = 20;
    char c = 'A';
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    mySwap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;
    // mySwap(a, c);
    
    double x = 1.5, y = 2.5;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    mySwap(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;
}

// 2、模板必须要确定出T的数据类型，才可以使用
template<typename T>
void func() {
    cout << "func函数调用！" << endl;
}

void func2() {
    // func();
    func<int>(); 
}

int main() {
    func1();
    func2();
    
    return 0;
}