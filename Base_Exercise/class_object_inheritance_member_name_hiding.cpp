#include "iostream"

using namespace std;

/*
 * 继承是面向对象三大特性之一
 *
 * 继承的语法：class 子类 : 继承方式  父类
 * 
 * 继承方式一共有三种：
 *      公共继承
 *      保护继承
 *      私有继承
 * 
 * 问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据呢？
 * 
 * 访问子类同名成员，直接访问即可
 * 访问父类同名成员，需要加作用域
 * 如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有（包括重载）同名成员函数 
 * 
 * 子类对象可以直接访问到子类中同名成员
 * 子类对象加作用域可以访问到父类同名成员
 * 当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数
 */

class Base {
public:
	Base()
	{
		m_A = 100;
	}

	void func()
	{
		cout << "Base - func()调用" << endl;
	}

	void func(int a)
	{
		cout << "Base - func(int a)调用" << endl;
	}

public:
	int m_A;
};

class Son : public Base {
public:
	Son()
	{
		m_A = 200;
	}

	// 当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
	// 如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
	void func()
	{
		cout << "Son - func()调用" << endl;
	}
public:
	int m_A;
};

void func()
{
	Son s;

	cout << "Son下的m_A = " << s.m_A << endl;
	cout << "Base下的m_A = " << s.Base::m_A << endl;

    s.func(); 
    s.Base::func(); 
    s.Base::func(10); 
}

int main()
{
    func();

    return 0;
}