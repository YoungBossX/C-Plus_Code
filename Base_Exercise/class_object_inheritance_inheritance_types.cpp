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
 */

class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};

//公共继承
class Son1 :public Base1
{
public:
	void func()
    {
        m_A = 10; // 类内可以访问父类的公有成员
        m_B = 20; // 类内可以访问父类的保护成员，类外不可访问
        // m_C = 30; // 不能访问父类的私有成员
    }
};

// 保护继承
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2 : protected Base2
{
public:
	void func()
	{
		m_A = 10; // 类内可访问 protected 权限，类外不可访问
		m_B = 20; // 类内可访问 protected 权限，类外不可访问
		//m_C; // 子类不可访问
	}
};

// 私有继承
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son3 : private Base3
{
public:
	void func()
	{
		m_A = 10; // 类内可访问 private 权限，类中公共成员到子类中变为私有成员，类外不可访问
		m_B = 20; // 类内可访问 private 权限，类中保护成员到子类中变为私有成员，类外不可访问
		// m_C; // 不可访问
	}
};

class GrandSon3 : public Son3
{
public:
	void func()
	{
		// Son3 是私有继承，所以继承 Son3 的属性在 GrandSon3 中都无法访问到
		// m_A;
		// m_B;
		// m_C;
	}
};

void func1()
{
    Son1 s1;
    s1.m_A = 100; // 可以访问父类的公有成员
    // s1.m_B = 200; // 不能访问父类的保护成员

    cout << "s1.m_A = " << s1.m_A << endl;
    cout << "sizeof Base1 = " << sizeof(Base1) << endl;
	cout << "sizeof Son = " << sizeof(Son1) << endl;
}

void func2()
{
    Son2 s2;
    // s2.m_A = 100; // 不能访问父类的公有成员，在 Son2 中 m_A 变为保护权限 ，因此类外访问不到
    // s2.m_B = 200; // 不能访问父类的保护成员，在 Son2 中 m_B 变为保护权限 ，因此类外访问不到

    cout << "sizeof Base2 = " << sizeof(Base2) << endl;
    cout << "sizeof Son2 = " << sizeof(Son2) << endl;
}

void func3()
{
    Son3 s3;
    // s3.m_A = 100; // 不能访问父类的公有成员，在 Son3 中 m_A 变为私有权限 ，因此类外访问不到
    // s3.m_B = 200; // 不能访问父类的保护成员，在 Son3 中 m_B 变为私有权限 ，因此类外访问不到

    cout << "sizeof Base3 = " << sizeof(Base3) << endl;
    cout << "sizeof Son3 = " << sizeof(Son3) << endl;
} 

int main() {
    func1();
    func2();
    func3();

    return 0;
}