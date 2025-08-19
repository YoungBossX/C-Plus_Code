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
 * 学习目标：
 *  - 类模板实例化出的对象，向函数传参的方式
 * 
 * 一共有三种传入方式：
 *  - 指定传入的类型 --- 直接显示对象的数据类型
 *  - 参数模板化 --- 将对象中的参数变为模板进行传递
 *  - 整个类模板化 --- 将这个对象类型模板化进行传递
 * 
 * 总结：
 *  - 通过类模板创建的对象，可以有三种方式向函数中进行传参
 *  - 使用比较广泛是第一种：指定传入的类型
 */

#include "iostream"

using namespace std;

template<class NameType, class AgeType = int> 
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};

// 1.指定传入的类型
void printPerson1(Person<string, int> &p) 
{
	p.showPerson();
}

void func1()
{
    Person<string, int> p("Tom", 20);
    printPerson1(p);
}

// 2.参数模板化
template <class T1, class T2>
void printPerson2(Person<T1, T2>&p)
{
	p.showPerson();
	cout << "T1的类型为： " << typeid(T1).name() << endl;
	cout << "T2的类型为： " << typeid(T2).name() << endl;
}

void func2()
{
	Person <string, int >p("Jerry", 20);
	printPerson2(p);
}

// 3,整个类模板化
template<class T>
void printPerson3(T& p)
{
	cout << "T的类型为： " << typeid(T).name() << endl;
	p.showPerson();

}
void func3()
{
	Person <string, int >p("XCC", 18);
	printPerson3(p);
}

int main() {
    func1();
    func2();
    func3();

    return 0;
}