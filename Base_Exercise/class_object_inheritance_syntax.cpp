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
 * C++允许一个类继承多个类
 * 语法：class 子类 ：继承方式 父类1 ， 继承方式 父类2...
 * 多继承可能会引发父类中有同名成员出现，需要加作用域区分
 * C++实际开发中不建议用多继承
 *
 * 总结：多继承中如果父类中出现了同名情况，子类使用时候要加作用域
 */

class Base1 {
public:
	Base1()
	{
		m_A = 100;
	}
public:
	int m_A;
};

class Base2 {
public:
	Base2()
	{
		m_A = 200;  //开始是m_B 不会出问题，但是改为mA就会出现不明确
	}
public:
	int m_A;
};

// 语法：class 子类：继承方式 父类1 ，继承方式 父类2 
class Son : public Base2, public Base1
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}
public:
	int m_C;
	int m_D;
};

void func1() {
    Son s;
    cout << "sizeof(Son) = " << sizeof(s) << endl;
    cout << "sizeof(Base1) = " << sizeof(Base1) << endl;
    cout << "sizeof(Base2) = " << sizeof(Base2) << endl;
    cout << "s.m_C = " << s.m_C << endl;
    cout << "s.m_D = " << s.m_D << endl;
    // cout << "s.m_A = " << s.m_A << endl; // 只一个继承对象的话可以访问
    cout << "s.Base1::m_A = " << s.Base1::m_A << endl;
    cout << "s.Base2::m_A = " << s.Base2::m_A << endl;
}

int main() {
    func1();

    return 0;
}