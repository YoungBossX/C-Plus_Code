/*
 * 主要针对C++泛型编程和ST技术做详细讲解，探讨C++更深层的使用
 *
 * 模板的概念
 *  - 模板就是建立通用的模具，大大提高复用性
 * 
 * 模板的特点
 *  - 模板不可以直接使用，它只是一个框架
 *  - 模板的通用并不是万能的
 * 
 * 类模板中成员函数和普通类中成员函数创建时机是有区别的：
 *  - 普通类中的成员函数一开始就可以创建
 *  - 类模板中的成员函数在调用时才创建
 * 
 * 总结：
 *  - 类模板中的成员函数并不是一开始就创建的，在调用时才去创建
 */

#include "iostream"

using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass
{
public:
	T obj;

	// 类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成
	void fun1() { obj.showPerson1(); }
	void fun2() { obj.showPerson2(); }
};

void func() {
    MyClass<Person1> m;
	m.fun1(); 
    MyClass<Person2> m2;
	m2.fun2();
}

int main() {
    func();

    return 0;
}