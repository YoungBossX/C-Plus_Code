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
 *  - 能够掌握类模板中的成员函数类外实现
 * 
 * 总结：
 *  - 类模板中成员函数类外实现时，需要加上模板参数列表
 */

#include "iostream"

using namespace std;

// 类模板中成员函数类外实现
template<class T1, class T2>
class Person {
public:
	// 成员函数类内声明
	Person(T1 name, T2 age);
	void showPerson();

public:
	T1 m_Name;
	T2 m_Age;
};

// 构造函数，类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}

// 成员函数，类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson() {
	cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
}

void func() {
    Person<string, int> p("XCC", 18);
    p.showPerson();
}

int main() {
    func();

    return 0;
}