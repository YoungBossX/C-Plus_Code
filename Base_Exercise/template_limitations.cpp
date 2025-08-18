/*
 * 主要针对C++泛型编程和ST技术做详细讲解，探讨C++更深层的使用
 *
 * 函数模板
 *  - C++另一种编程思想称为泛型编程 ，主要利用的技术就是模板
 *  - C++提供两种模板机制：函数模板和类模板
 * 
 * 局限性：
 *  - 模板的通用性并不是万能的
 * 
 * C++为了解决这种问题，提供模板的重载，可以为这些特定的类型提供具体化的模板
 * 
 * 总结：
 *  - 利用具体化的模板，可以解决自定义类型的通用化
 *  - 学习模板并不是为了写模板，而是在STL能够运用系统提供的模板
 */

#include <iostream>

using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 具体化，显示具体化的原型和定意思以template<>开头，并通过名称来指出类型
// 具体化优先于常规模板
template<> bool myCompare(Person &p1, Person &p2) {
	if ( p1.m_Name  == p2.m_Name && p1.m_Age == p2.m_Age) {
		return true;
	} else {
		return false;
	}
}

void func1(){
    int a = 10;
    int b = 20;
    myCompare(a, b);

    if (myCompare(a, b)) {
        cout << "a == b" << endl;
    } else {
        cout << "a != b" << endl;
    }
}

void func2() {
    Person p1("Tom", 10);
    Person p2("Jerry", 10);

    if (myCompare(p1.m_Age, p2.m_Age)) {
        cout << "p1 == p2" << endl;
    } else {
        cout << "p1 != p2" << endl;
    }
}

int main() {
    func1();
    func2();

    return 0;
}