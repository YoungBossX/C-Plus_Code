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
 * 当类模板碰到继承时，需要注意一下几点：
 *  - 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
 *  - 如果不指定，编译器无法给子类分配内存
 *  - 如果想灵活指定出父类中T的类型，子类也需变为类模板
 * 
 * 总结：
 *  - 如果父类是类模板，子类需要指定出父类中T的数据类型
 */

#include "iostream"

using namespace std;

template<class T>
class Base
{
	T m;
};

//class Son:public Base  // 错误，C++ 编译需要给子类分配内存，必须知道父类中T的类型才可以向下继承
class Son1 :public Base<int> // 必须指定一个类型
{

};

void func()
{
	Son1 c;
}

// 如果想灵活指定父类中T类型，子类也需要变类模板
template<class T1, class T2>
class Son2 : public Base<T1>
{
public:
    T2 m;

	Son2()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
};

void func2()
{
    Son2<int, char> c;
}

int main() {
    func();
    func2();

    return 0;
}