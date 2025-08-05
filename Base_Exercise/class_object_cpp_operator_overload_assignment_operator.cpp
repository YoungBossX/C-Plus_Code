#include "iostream"

using namespace std;

/*
 * 运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
 *
 * c++编译器至少给一个类添加4个函数
 *  - 默认构造函数(无参，函数体为空)
 *  - 默认析构函数(无参，函数体为空)
 *  - 默认拷贝构造函数，对属性进行值拷贝
 *  - 赋值运算符 operator=, 对属性进行值拷贝
 * 
 * 如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
 * 值拷贝只会拷贝指针的值（地址），不会拷贝指针指向的内容，这叫浅拷贝
 * 如果类中有成员是指针，需要自己写拷贝构造和赋值运算符，实现深拷贝，否则容易出现内存泄漏或指针悬空等问题
 * 
 */

class Person
{
public:
	int *m_Age;

	Person(int age)
	{
		// 将年龄数据开辟到堆区
		m_Age = new int(age);
	}

	// 重载赋值运算符 
	Person& operator=(Person &p)
	{
        // 赋值前先清空原有数据
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}

		// 编译器提供的代码是浅拷贝
		//m_Age = p.m_Age;

		// 提供深拷贝，解决浅拷贝的问题
		m_Age = new int(*p.m_Age);

		// 返回自身
		return *this;
	}

	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
};

void func() {
    Person p1(18);

	Person p2(20);

	Person p3(30);

	p3 = p2 = p1;

	cout << "p1的年龄为：" << *p1.m_Age << endl;

	cout << "p2的年龄为：" << *p2.m_Age << endl;

	cout << "p3的年龄为：" << *p3.m_Age << endl;
}


int main() {
    // 如果不重载赋值运算符，编译器会提供默认的赋值运算符
    // 但是默认的赋值运算符是浅拷贝，可能会导致内存泄漏或双重释放
    // 所以需要重载赋值运算符，提供深拷贝
    func();

    // 连续赋值
	//int a = 10;
	//int b = 20;
	//int c = 30;

	//c = b = a;
	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;
	//cout << "c = " << c << endl;

    return 0;
}