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
 * 子类继承父类后，当创建子类对象，也会调用父类的构造函数
 * 问题：父类和子类的构造和析构顺序是谁先谁后？
 * 
 * 总结：继承中先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
 */

class Base 
{
public:
	Base()
	{
		cout << "Base构造函数!" << endl;
	}
	~Base()
	{
		cout << "Base析构函数!" << endl;
	}
};

class Son : public Base
{
public:
	Son()
	{
		cout << "Son构造函数!" << endl;
	}
	~Son()
	{
		cout << "Son析构函数!" << endl;
	}

};

void func1()
{
	Son son;
}

int main() {
    func1();

	return 0;
}